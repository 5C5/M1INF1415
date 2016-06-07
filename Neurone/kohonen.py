# coding: utf8
#!/usr/bin/env python
# ------------------------------------------------------------------------
# Carte de Kohonen
# Écrit par Mathieu Lefort
#
# Distribué sous licence BSD.
# ------------------------------------------------------------------------
# Implémentation de l'algorithme des cartes auto-organisatrices de Kohonen
# ------------------------------------------------------------------------
# Pour que les divisions sur les entiers soient des divisions réelles
from __future__ import division
# Librairie de calcul matriciel
import numpy
# Librairie d'affichage
import matplotlib.pyplot as plt
# Pour lire les données MNIST
import gzip, cPickle

def V(pos_bmu,shape,sigma):
    '''
    @summary: Fonction de voisinage
    @param pos_bmu: Position de l'unité gagnante
    @type pos_bmu: tuple
    @param shape: Taille de la SOM
    @type shape: tuple
    @param sigma: Largeur du voisinage
    @type sigma: float
    @return: La fonction de voisinage pour chaque unité de la SOM (numpy.array)
    '''
    
    x,y = numpy.ogrid(shape)
    vois = -((x - pos_bmu[0])**2 + (y - pos_bmu[1])**2)
    vois = vois / (2 * sigma ** 2)
    vois = numpy.exp(vois)
    
    vois = [:,: numpy.newaxis, numpy.newaxis]

    
    return vois

def distance(W,X):
    '''
    @summary: Fonction de distance
    @param W: Poids de la SOM
    @type W: numpy.array
    @param X: Entrée courante
    @type X: numpy.array
    @return: La distance entre l'entrée courante et le prototype pour chaque unité de la SOM (numpy.array)
    '''
    X = X[numpy.newaxis,numpy.newaxis,:,:]

    temp = W - X;
    temp = temp**2;
    temp = numpy.sqrt(temp);

    distance = numpy.sum(temp, 2)

    return distance

class SOM:
    ''' Classe implémentant une carte de Kohonen. '''

    def __init__(self, *args):
        '''
        @summary: Création du réseau
        @param args: Liste de taille des couches
        @type args: tuple
        '''
        # Taille des couches ((s1,...,sn),(i1,...,im)) si la SOM fait s1*...*sn et l'entrée fait i1*...*im
        self.shape = args
        # Label associé à chaque unité de la carte (array de taille (s1,...,sn))
        self.labeling = numpy.empty(self.shape[1])
        # Entrée de la carte (array de taille (i1,...,im))
        self.X = numpy.empty(self.shape[0])
        # Poids de la carte (prototypes) (array de taille (s1,...,sn,i1,...,im))
        self.W = numpy.empty(self.shape[1]+self.shape[0])
        # Initialisation des poids
        self.reset()

    def reset(self):
        ''' 
        @summary: Initialisation des poids entre -1 et 1
        '''
        self.W = numpy.random.random(self.shape[1]+self.shape[0])*2.-1.

    def learn(self,train_samples,epochs,eta,sigma,verbose=False):
        '''
        @summary: Apprentissage du modèle
        @param train_sample: Ensemble des données d'entraînement
        @type train_sample: dictionnaire ('input' est un numpy.array qui contient l'ensemble des vecteurs d'entrées, 'output' est un numpy.array qui contient l'ensemble des vecteurs de sortie correspondants)
        @param epochs: Nombre de pas d'apprentissage
        @type epochs: int
        @param eta: Taux d'apprentissage
        @type eta: float
        @param sigma: Largeur du voisinage
        @type sigma: float
        @param verbose: Indique si l'affichage est activé (utilisable uniquement avec des entrées à deux dimensions)
        @type verbose: boolean
        '''
        # Initialisation de l'affichage
        if verbose:
            # Création d'une figure
            plt.figure()
            # Mode interactif
            plt.ion()
            # Affichage de la figure
            plt.show()
        for i in range(1,epochs+1):
            # Choix d'un exemple aléatoire
            n = numpy.random.randint(train_samples['input'].shape[0])
            # Entrée courante
            self.X[:,:] = train_samples['input'][n]
            # Mise à jour des poids (utiliser les fonctions V et distance, les poids (self.W) et l'entrée (self.X))
            # TODO
            # Sortie correspondant à l'entrée courante
            output = train_samples['output'][n]
            # Apprentissage de la labelisation (avec la méthode de votre choix)
            # TODO (optionnel)
            # Mise à jour de l'affichage
            if verbose and i%1000==0:
                # Effacement du contenu de la figure
                plt.clf()
                # Remplissage de la figure
                self.scatter_plot(True)
                # Affichage du contenu de la figure
                plt.draw()
        # Fin de l'affichage interactif
        if verbose:
            # Désactivation du mode interactif
            plt.ioff()                
                
    def test(self,test_samples,verbose=False):
        '''
        @summary: Test du modèle (classification)
        @param test_samples: Ensemble des données de test
        @type test_samples: dictionnaire ('input' est un numpy.array qui contient l'ensemble des vecteurs d'entrées, 'output' est un numpy.array qui contient l'ensemble des vecteurs de sortie correspondants)
        @param verbose: Indique si l'affichage est activé (False par défaut)
        @type verbose: boolean
        '''
        # Nombre d'erreurs de classification
        error = 0.
        for i in range(test_samples['input'].shape[0]):
            # Calcul du label correspondant à l'exemple de test courant
            label = 0 # TODO à affecter suivant l'algorithme que vous aurez choisi (optionnel)
            # Augmentation du nombre d'erreur si le max de la sortie ne correspond pas à la catégorie attendue
            error += 0. if label==test_samples['output'][i][0] else 1.
            # Affichage des résultats
            if verbose:
              print 'entrée', test_samples['input'][i], 'sortie ', label, '(attendue)', test_samples['output'][i][0]
        # Affichage du pourcentage d'erreurs de classification
        print 'erreur de classification ',error/test_samples['input'].shape[0]*100.,'%'

    def scatter_plot(self,interactive=False):
        '''
        Affichage du réseau dans l'espace d'entrée (utilisable dans le cas d'entrée à deux dimensions et d'une carte avec une topologie de grille)
        @param interactive: Indique si l'affichage se fait en mode interactif
        @type interactive: boolean
        '''
        # Création de la figure
        if not interactive:
            plt.figure()
        # Récupération des poids
        w = self.W
        # Affichage des poids
        plt.scatter(w[:,:,0].flatten(),w[:,:,1].flatten(),c='k')
        # Affichage de la grille
        for i in xrange(w.shape[0]):
            plt.plot(w[i,:,0],w[i,:,1],'k',linewidth=1.)
        for i in xrange(w.shape[1]):
            plt.plot(w[:,i,0],w[:,i,1],'k',linewidth=1.)
        # Modification des limites de l'affichage
        plt.xlim(-1,1)
        plt.ylim(-1,1)
        # Affichage de la figure
        if not interactive:
            plt.suptitle('representation de la carte dans l\'espace d\'entree')
            plt.show()
  
    def plot(self):
        '''
        Affichage des poids du réseau (matrice des poids)
        '''
        # Création de la figure
        plt.figure()
        # Récupération des poids
        w = self.W
        # Affichage des poids dans un sous graphique (suivant sa position de la SOM)
        for i in xrange(w.shape[0]):
            for j in xrange(w.shape[1]):
                plt.subplot(w.shape[0],w.shape[1],i*w.shape[1]+j+1)
                plt.imshow(w[i,j],interpolation='nearest',vmin=-1,vmax=1,cmap='binary')
                plt.xticks([])
                plt.yticks([])
        # Affichage de la figure
        plt.suptitle('poids de chaque neurone dans la carte')
        plt.show()


# -----------------------------------------------------------------------------
if __name__ == '__main__':
    # Création d'un réseau avec une entrée (2,1) et une carte (10,10)
    network = SOM((2,1),(10,10))
    # Exemple 1 :
    # -------------------------------------------------------------------------
    # Création des données d'apprentissage bidimensionnelles
    n = 1000
    train_input = numpy.random.random((n,2,1))*2.-1.
    train_output = numpy.empty((n,1))
    train_output[numpy.where(numpy.logical_and(train_input[:,0]<0,train_input[:,1]<0))] = 1
    train_output[numpy.where(numpy.logical_and(train_input[:,0]<0,train_input[:,1]>0))] = 2
    train_output[numpy.where(numpy.logical_and(train_input[:,0]>0,train_input[:,1]<0))] = 3
    train_output[numpy.where(numpy.logical_and(train_input[:,0]>0,train_input[:,1]>0))] = 4
    train = {'input':train_input,'output':train_output}
    # Création des données de test bidimensionnelles
    n = 100
    test_input = numpy.random.random((n,2,1))*2.-1.
    test_output = numpy.empty((n,1))
    test_output[numpy.where(numpy.logical_and(test_input[:,0]<0,test_input[:,1]<0))] = 1
    test_output[numpy.where(numpy.logical_and(test_input[:,0]<0,test_input[:,1]>0))] = 2
    test_output[numpy.where(numpy.logical_and(test_input[:,0]>0,test_input[:,1]<0))] = 3
    test_output[numpy.where(numpy.logical_and(test_input[:,0]>0,test_input[:,1]>0))] = 4
    test = {'input':test_input,'output':test_output}
    
    # TODO Pour les données mnist
    # ATTENTION À: la localisation du fichier, la taille du réseau, les affichages scatter_plot à supprimer
#    data = cPickle.load(gzip.open('mnist.pkl.gz'))
#    train = {'input':data[0][0].reshape(56000,28,28),'output':numpy.argmax(data[0][1],axis=1)}
#    test = {'input':data[2][0].reshape(7000,28,28),'output':numpy.argmax(data[2][1],axis=1)}
    
    # Initialisation du réseau
    network.reset()
    # Performance du réseau avant apprentissage
    # TODO Uniquement pertinent si la labelisation est faite (à décommenter pour la partie B optionnelle)
    #print "Avant apprentissage"
    #network.test(test,False)
    # Affichage du réseau dans l'espace d'entrée (puisqu'il est à deux dimensions)
    # TODO Uniquement pertinent dans le cas d'entrées à deux dimensions (à commenter pour les données MNIST)
    network.scatter_plot()
    # Affichage des poids du réseau
    network.plot()
    # Apprentissage du réseau
    # TODO NB Verbose à True uniquement pertinent dans le cas d'entrées à deux dimensions (à mettre à False pour les données MNIST)
    network.learn(train,30000,0.05,1.,True)
    # Performance du réseau après apprentissage
    # TODO Uniquement pertinent si la labelisation est faite (à décommenter pour la partie B optionnelle)
    #print "Apres apprentissage"
    #network.test(test,False)
    # Affichage du réseau dans l'espace d'entrée (puisqu'il est à deux dimensions)
    # TODO NB Uniquement pertinent dans le cas d'entrées à deux dimensions (à commenter pour les données MNIST)
    network.scatter_plot()
    # Affichage des poids du réseau
    network.plot()

