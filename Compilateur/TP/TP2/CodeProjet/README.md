# README du projet COMPILATEUR
-----
Colas PICARD
p1410822

# Avancée du projet au 06/12
Le programme génère un core dump, qui semble provenir des expressions mathématiques.
Un second élément générant le core dump est la regle VarExpr		: TOK_IDENT, dont le traitement semble être problématique.
Il n'y a donc pas d'écriture de code 3@. Des instructions sont stockées, mais leur transformation en code 3@ et leur écriture ne sont pas gérées.

