# coding: utf8
#!/usr/bin/env python
# ------------------------------------------------------------------------------
# Perceptron multicouches
# Copyright (C) 2011  Nicolas P. Rougier
# Modifié par Mathieu Lefort
#
# Distribué sous licence BSD.
# ------------------------------------------------------------------------------
# Implémentation d'un perceptron multicouches avec rétropropagation du gradient.
# ------------------------------------------------------------------------------
# Librairie de calcul matriciel
import numpy
# Pour lire les données MNIST
import gzip, cPickle

def sigmoid(x):
    '''
    @summary: Équation d'une sigmoïde
    @param x: Valeur d'entrée
    @type x: numpy.array
    @return: La sigmoïde appliquée au point x (numpy.array)
    '''
    return 1./(1.+numpy.exp(-x))

def dsigmoid(x):
    '''
    @summary: Dérivée de la fonction sigmoid
    @param x: Valeur d'entrée
    @type x: numpy.array
    @return: La dérivée appliquée au point x (numpy.array)
    '''
    return x*(1.-x)

class MLP:
    ''' Classe implémentant un perceptron multicouches '''

    def __init__(self, *args):
        '''
        @summary: Création du réseau
        @param args: Liste de la taille des couches
        @type args: tuple
        '''
        # Taille des couches
        self.shape = args
        # Nombre de couches
        n = len(args)
        # Construction des couches
        self.layers = []
        # Couche d'entrée (+1 pour le biais)
        self.layers.append(numpy.ones(self.shape[0]+1))
        # Couches cachées et couche de sortie
        for i in range(1,n):
            self.layers.append(numpy.ones(self.shape[i]))
        # Construction des connexions entre les couches
        self.weights = []
        for i in range(n-1):
            self.weights.append(numpy.zeros((self.layers[i+1].size,self.layers[i].size)))
        # Initialisation des poids
        self.reset()

    def reset(self):
        ''' 
        @summary: Initilisation des poids entre -1 et 1
        '''
        for i in range(len(self.weights)):
            self.weights[i][:] = numpy.random.random((self.layers[i+1].size,self.layers[i].size))*2.-1.

    def propagate_forward(self, data):
        '''
        @summary: Propagation de l'entrée à travers les couches cachées jusqu'à la couche de sortie
        @param data: L'entrée courante
        @type data: numpy.array
        @return: L'activité de la couche de sortie (numpy.array)
        '''
        # Mise à jour de la couche d'entrée
        self.layers[0][0:-1] = data
        # Propagation de l'activité dans les couches cachées et la couche de sortie
        for i in range(1,len(self.shape)):
            self.layers[i][:] = sigmoid(numpy.dot(self.weights[i-1],self.layers[i-1]))
        # Renvoie l'activité de la couche de sortie
        return self.layers[-1]


    def propagate_backward(self, target, lrate):
        '''
        @summary: Mise à jour des poids par rétropropagation du gradient
        @param target: La sortie attendue
        @type target: numpy.array
        @param lrate: Le taux d'apprentissage
        @type lrate: float
        '''
        deltas = []
        # Calcul de l'erreur de la couche de sortie
        error = target - self.layers[-1]
        delta = error*dsigmoid(self.layers[-1])
        deltas.append(delta)
        # Rétropropagation du gradient dans les couches cachées
        for i in range(len(self.shape)-2,0,-1):
            delta = numpy.dot(deltas[0],self.weights[i])*dsigmoid(self.layers[i])
            deltas.insert(0,delta)
        # Mise à jour des poids
        for i in range(len(self.weights)):
            inp = self.layers[i][numpy.newaxis,:]
            delta = deltas[i][:,numpy.newaxis]
            self.weights[i] += lrate*delta*inp

    def learn(self,train_samples,epochs,lrate,verbose=False):
        '''
        @summary: Apprentissage du modèle
        @param train_sample: Ensemble des données d'entraînement
        @type train_sample: dictionnaire ('input' est un numpy.array qui contient l'ensemble des vecteurs d'entrées, 'output' est un numpy.array qui contient l'ensemble des vecteurs de sortie correspondants)
        @param epochs: Nombre de pas d'apprentissage
        @type epochs: int
        @param lrate: Taux d'apprentissage
        @type lrate: float
        @param verbose: Indique si l'affichage est activé (False par défaut)
        @type verbose: boolean
        '''
        for i in range(epochs):
            # Choix d'un exemple aléatoire
            n = numpy.random.randint(train_samples['input'].shape[0])
            # Propagation de l'activité
            self.propagate_forward(train_samples['input'][n])
            # Apprentissage par rétropropagation du gradient
            error = self.propagate_backward(train_samples['output'][n], lrate)
            # Affichage de l'erreur courante
            if verbose and i%1000==0:
              print 'epoch ',i,' error ',error
    
    def test_regression(self,test_samples,verbose=False):
        '''
        @summary: Test du modèle (erreur quadratique moyenne)
        @param test_samples: Ensemble des données de test
        @type test_samples: dictionnaire ('input' est un numpy.array qui contient l'ensemble des vecteurs d'entrées, 'output' est un numpy.array qui contient l'ensemble des vecteurs de sortie correspondants)
        @param verbose: Indique si l'affichage est activé (False par défaut)
        @type verbose: boolean
        '''
        # Erreur quadratique moyenne
        error = 0.
        for i in range(test_samples['input'].shape[0]):
            # Calcul de la sortie correspondant à l'exemple de test courant
            o = self.propagate_forward( test_samples['input'][i] )
            # Mise à jour de l'erreur quadratique moyenne
            error += numpy.sum((o-test_samples['output'][i])**2)
            # Affichage des résultats
            if verbose:
              print 'entree', test_samples['input'][i], 'sortie %.2f' % o, '(attendue %.2f)' % test_samples['output'][i]
        # Affichage de l'erreur quadratique moyenne
        print 'erreur quadratique moyenne ',error/test_samples['input'].shape[0]

    def test_classification(self,test_samples):
        '''
        @summary: Test du modèle (classification)
        @param test_samples: Ensemble des données de test
        @type test_samples: dictionnaire ('input' est un numpy.array qui contient l'ensemble des vecteurs d'entrées, 'output' est un numpy.array qui contient l'ensemble des vecteurs de sortie correspondants)
        '''
        # Nombre d'erreurs de classification
        error = 0.
        for i in range(test_samples['input'].shape[0]):
            # Calcul de la sortie correspondant à l'exemple de test courant
            o = self.propagate_forward( test_samples['input'][i] )
            # Augmentation du nombre d'erreur si le max de la sortie ne correspond pas à la catégorie attendue
            error += 0. if numpy.argmax(o)==numpy.argmax(test_samples['output'][i]) else 1.
            # Affichage des résultats
        # Affichage du pourcentage d'erreurs de classification
        print 'erreur de classification ',error/test_samples['input'].shape[0]*100,'%'

# -----------------------------------------------------------------------------
if __name__ == '__main__':
    # Création d'un réseau avec deux entrées, 5 neurones dans la couche cachée et 1 neurone de sortie
    network = MLP(2,5,1)

    # Exemple 1 : la fonction OU
    # -------------------------------------------------------------------------
    print "==============================="
    print "Apprentissage de la fonction OU"
    print "==============================="
    # Création des données d'apprentissage
    train_input = numpy.array([[0,0],[0,1],[1,0],[1,1]])
    train_output = numpy.array([[0],[1],[1],[1]])
    train = {'input':train_input,'output':train_output}
    # Ici les données de tests sont les mêmes
    test = train.copy()
    # Initialisation du réseau
    network.reset()
    # Performance du réseau avant apprentissage
    print "Avant apprentissage"
    network.test_regression(test,True)
    # Apprentissage du réseau
    network.learn(train,50000,0.1,False)
    # Performance du réseau après apprentissage
    print "Apres apprentissage"
    network.test_regression(test,True)

    # Exemple 2 : la fonction ET
    # -------------------------------------------------------------------------
    print "==============================="
    print "Apprentissage de la fonction ET"
    print "==============================="
    # Création des données d'apprentissage
    train_input = numpy.array([[0,0],[0,1],[1,0],[1,1]])
    train_output = numpy.array([[0],[0],[0],[1]])
    train = {'input':train_input,'output':train_output}
    # Ici les données de tests sont les mêmes
    test = train.copy()
    # Initialisation du réseau
    network.reset()
    # Performance du réseau avant apprentissage
    print "Avant apprentissage"
    network.test_regression(test,True)
    # Apprentissage du réseau
    network.learn(train,50000,0.1,False)
    # Performance du réseau après apprentissage
    print "Apres apprentissage"
    network.test_regression(test,True)

    # Exemple 3 : La fonction XOR
    # -------------------------------------------------------------------------
    print "================================"
    print "Apprentissage de la fonction XOR"
    print "================================"
    # Création des données d'apprentissage
    train_input = numpy.array([[0,0],[0,1],[1,0],[1,1]])
    train_output = numpy.array([[0],[1],[1],[0]])
    train = {'input':train_input,'output':train_output}
    # Ici les données de tests sont les mêmes
    test = train.copy()
    # Initialisation du réseau
    network.reset()
    # Performance du réseau avant apprentissage
    print "Avant apprentissage"
    network.test_regression(test,True)
    # Apprentissage du réseau
    network.learn(train,50000,0.1,False)
    # Performance du réseau après apprentissage
    print "Apres apprentissage"
    network.test_regression(test,True)


    # TODO Pour MNIST (attention à bien changer la taille du réseau et à le paramétrer correctement)
    # Récupération des données
#    data = cPickle.load(gzip.open('mnist.pkl.gz'))
#    train = {'input':data[0][0],'output':data[0][1]}
#    test = {'input':data[2][0],'output':data[2][1]}
    # Initialisation du réseau
#    network.reset()
    # Performance du réseau avant apprentissage
#    print "Avant apprentissage"
#    network.test_classification(test)
    # Apprentissage du réseau
#    network.learn(train,50000,0.1,False)
    # Performance du réseau après apprentissage
#    print "Apres apprentissage"
#    network.test_classification(test)

