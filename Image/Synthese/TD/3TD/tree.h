#ifndef TREE_H
#define TREE_H
#include "outils.hpp"
#include "td.hpp"
class Tree{

public:
    enum TypeTree {POMMIER, PLATANE};
    Tree(Point3f, TypeTree, int);
    Maillage & getMaillage();
    bool isNear(Point3f);


protected :
    int id;
    Point3f graine;
    float hauteur;
    float circonference;
    float rayonA;
    int age;
    TypeTree espece;



};

#endif // TREE_H
