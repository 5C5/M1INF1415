# coding: utf8
#!/usr/bin/env python
# ------------------------------------------------------------------------
# Tutoriel succint de numpy
# Écrit par Mathieu Lefort
#
# Distribué sous licence BSD.
# ------------------------------------------------------------------------

import numpy
print "============================================================================="
print "|| Petit tutoriel de numpy. Ce qui est entre '' est le code python qui est ||\n|| executé, en dessous est l'éventuel résultat de l'exécution de ce code.  ||"
print "============================================================================="
print "============================================================================="
print "|| Création d'un tableau t par énumération explicite de ses éléments       ||"
print "============================================================================="
print "'t = numpy.array([[1,2,3],[4,5,6]])'"
t = numpy.array([[1,2,3],[4,5,6]])
print "============================================================================="
print "|| Affichage du tableau et de sa taille                                    ||"
print "============================================================================="
print "'print t'"
print t
print "'print t.shape'"
print t.shape
print "============================================================================="
print "|| Transformation de t en vecteur                                          ||"
print "============================================================================="
print "'t = t.flatten()'"
t = t.flatten()
print "============================================================================="
print "|| Affichage du tableau et de sa taille                                    ||"
print "============================================================================="
print "'print t'"
print t
print "'print t.shape'"
print t.shape
print "============================================================================="
print "|| Modification de la taille du tableau (remise à sa taille d'origine)     ||"
print "============================================================================="
print "'t = t.reshape((2,3))'"
t = t.reshape((2,3))
print "============================================================================="
print "|| Affichage du tableau et de sa taille                                    ||"
print "============================================================================="
print "'print t'"
print t
print "'print t.shape'"
print t.shape
print "============================================================================="
print "|| Affichage de certain(e)s éléments/parties du tableau                    ||"
print "============================================================================="
print "'t[0,0]'"
print t[0,0]
print "'t[:,0]'"
print t[:,0]
print "'t[0,1:3]'"
print t[0,1:3]
print "============================================================================="
print "|| Recherche de l'indice du plus grand élément du tableau                  ||"
print "============================================================================="
print "'numpy.argmax(t)'"
print numpy.argmax(t)
print "============================================================================="
print "|| Recherche de l'indice du plus grand élément du tableau et calcul de sa  ||\n|| position dans le tablea (par rapport à la taille du tableau)            ||"
print "============================================================================="
print "'numpy.unravel_index(numpy.argmax(t),t.shape)'"
print numpy.unravel_index(numpy.argmax(t),t.shape)
print "============================================================================="
print "|| Somme de (certains) éléments du tableau                                 ||"
print "============================================================================="
print "'numpy.sum(t)'"
print numpy.sum(t)
print "'numpy.sum(t,axis=1)'"
print numpy.sum(t,axis=1)
print "============================================================================="
print "|| Création d'un autre tableau à partir de t                               ||"
print "============================================================================="
print "'t2 = t'"
t2 = t
print "============================================================================="
print "|| Attention ce n'est pas une copie mais juste le pointeur vers le tableau ||\n|| qui est recopié                                                         ||"
print "============================================================================="
print "'t[0,0] = 7'"
t[0,0] = 7
print "'print t'"
print t
print "'print t2'"
print t2
print "============================================================================="
print "|| Création d'une copie de t                                               ||"
print "============================================================================="
print "'t3 = t.copy()'"
t3 = t.copy()
print "'t[0,0] = 1'"
t[0,0] = 1
print "'print t'"
print t
print "'print t3'"
print t3
print "============================================================================="
print "|| Transposée d'un tableau                                                 ||"
print "============================================================================="
print "'t3.T'"
print t3.T
print "============================================================================="
print "|| Diverses opération sur les tableaux. (+,-,*,/,**) sont des opérations   ||\n|| terme à terme, le produit matricielle est numpy.dot                     ||"
print "============================================================================="
print "'print t+t3'"
print t+t3
print "'print t*t3'"
print t*t3
print "'print 2*t'"
print 2*t
print "'print t**2'"
print t**2
print "'numpy.dot(t,t3.T)'"
print numpy.dot(t,t3.T)

print "============================================================================="
print "|| Création de tableaux 'spécifiques'                                      ||"
print "============================================================================="
print "'x,y = numpy.ogrid[0:2,0:3]'"
x,y = numpy.ogrid[0:2,0:3]
print "'print x'"
print x
print "'print y'"
print y
print "'print x.shape'"
print x.shape
print "'print y.shape'"
print y.shape
print "'r = numpy.arange(5)'"
r = numpy.arange(5)
print "'print r'"
print r
print "'z = numpy.zeros((5,4))'"
z = numpy.zeros((5,4))
print "'print z'"
print z
print "============================================================================="
print "|| Pour les opérations sur les tableaux il faut que les dimensions soient  ||\n|| 'cohérentes'                                                            ||"
print "============================================================================="
print "'print r.shape'"
print r.shape
print "'print z.shape'"
print z.shape
print "'print r+z'"
try:
    print r+z
except Exception as e:
    print e
print "============================================================================="
print "|| Par contre numpy peut étendre le tableau sur les axes si ils sont       ||\n|| existants (rajout d'un axe à r puis somme avec z)                       ||"
print "============================================================================="
print "'r = r[:,numpy.newaxis]'"
r = r[:,numpy.newaxis]
print "'print r.shape'"
print r.shape
print "'print r+z'"
print r+z
print "'print x+y'"
print x+y
