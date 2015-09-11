#ifndef TD_HPP
#define TD_HPP

#include "outils.hpp"


class Maillage {


	protected :
        vector<Point3f> geom;
        vector<int> topo;

    public:
        Maillage(){};
        Maillage(const vector<Point3f> &nGeo, const vector<int> &nTopo) : geom(nGeo), topo(nTopo) {};
        ~Maillage(){};

		vector<Point3f>& getGeom();
		vector<int>& getTopo();

        void zero();
        void translate(const Point3f&);
        void rotate(const Mat&);
     	void merge(Maillage &);
        void loadFromOBJ(const string&);
        void writeIntoOBJ(const string&);


		/* Fonctions de créations d'objet */
		Maillage cube(const Point3f &, const Point3f &);
		Maillage cylinder(const Point3f&, float, float);		
        Maillage cylinder(const Point3f &, const Point3f &, float );  
        Maillage cone(const Point3f&, float, const Point3f&);
        //Maillage cone(const Point3f&, float, float);
		Maillage sphere(const Point3f&, float);
        Maillage torus(const Point3f&, float, float);
	    Maillage test(float, float, float, float);
		Maillage temple(Point3f &, Point3f &);
};
#endif
