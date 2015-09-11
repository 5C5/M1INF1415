#include "tree.h"

Tree::Tree(Point3f o, TypeTree espece, int age){
    static int i = 0;
    this->id = i++;
    this->age = age;
    this->graine = o;
    this->espece = espece;
    if(espece == PLATANE){
        this->hauteur = 1 + age % 6 + (1/(age + 1)) * age;
        this->circonference = 0.7 + 3/(age + 1) * age;
        this->rayonA = 2* this->circonference;
    }else{
        this->hauteur = 1 + age % 4 + (1/(age + 1)) * age;
        this->circonference = 0.5 + 2/(age + 1) * age;
        this->rayonA = 2.5 * this->circonference;
    }

}

bool Tree::isNear(Point3f a){
    return norm(a - this->graine) < this->rayonA;
}
