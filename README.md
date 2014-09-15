M1INF1415
=========

Bienvenue sur le Dépôt de la promo 2014-2015 du Master 1 Informatique


Trois petites règles :
-Pas de copie de code : on peut regarder, réutiliser les algos... mais c'est tout.
-Tout abus sera puni. Et Je saurais qui c'est, de toute façon...
-Dans le doute, faite une branche, forkez le dépôt.. mais évitez les problèmes

# Utiliser GIT (facilement)

##Installation

* [Pour Windows] , c'est tout nouveau, apparemment c'est intuitif et ça fonctionne bien, je vous laisse découvrir !
* [Pour Mac] , c'est tout nouveau, apparemment c'est intuitif et ça fonctionne bien, je vous laisse découvrir !
* Pour (Maître) Linux , le paquet _git_ est nécessaire; voir ci-dessous pour découvrir.

Debian et dérivés:
```Bash
sudo apt-get install git
```
Fedora:
```Bash
sudo yum install git
```

[Pour Windows]: http://windows.github.com
[Pour Mac]: http://mac.github.com
NB: pour Windows et Mac, le tuto s'arrête ici. Pour Linux également, ils existe des logiciels (tig, gitk,...) pour gérer git sans passser (ou presque) par les commandes expliquées dans la suite du tuto.  


##Configuration (Linux)

Quelques étapes de configuration vous seront nécessaire pour pouvoir utiliser Git tranquillement.

###Les couleurs

```Bash
git config --global color.diff auto
git config --global color.status auto
git config --global color.branch auto
```

###Les informations diverses

```Bash
git config --global user.name "Votre nom/pseudo"
git config --global user.email "Votre e-mail utilisé pour vous inscrire sur github"
git config --global credential.helper cache
git config --global credential.helper 'cache --timeout=3600' #garde le mot de passe en cache 3600s après authentification réussie, c'est plus pratique
```

###Ajouter le repo et rediriger les push sur le repo commun

```Bash
git remote add upstream https://github.com/5C5/M1INF1415.git
git fetch upstream
```

##Utilisation (pour Linux)

En seulement 4 étapes !

1.Mettre à jour le dossier partagé

```Bash
cd "Le chemin vers le dossier cloné"
git pull
```
**Rep tant que "Travail non finit"**

2.Faire un changement (travail)

3.Commiter le changement, càd mise à jour locale (Dire la mise à jour qu'on a effectué lors de nos dernières actions"
```Bash
git commit -a
```
**Fin rep**

4.Pusher votre travail (Mettre à jour le repo)
```Bash
git push
```

#That's all
![Obama](http://voyagerloin.com/wp-content/uploads/2013/08/Obama-reddit-ama-not-bad.jpg "Tu as réussi")
