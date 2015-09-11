#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "td.hpp"
#include "outils.hpp"
#include "tree.h"

class Terrain : public Maillage{

    protected :
        float x, y, size, pasX, pasY;
        vector<Tree> flore;

	public:

		Terrain(float n = 100, float m = 100, float taille = 300);
        Terrain(float, string);
        void addSimplePerlin();
        void resethigh();
        void addDoubleNoise();
        void addWeirdNoise();
        void addSeuil(double);
        void addSeuilBruite(double);
        void addTrees();
        bool isViable(Point3f *);

};

#endif
