
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/nonfree/features2d.hpp"

using namespace std;
using namespace cv;

#ifndef TD_HPP
#define TD_HPP


class Maillage {


	protected :
        vector<Point3f> geom;
        vector<int> topo;

    public:
        Maillage(){};
        Maillage(const vector<Point3f> &nGeo, const vector<int> &nTopo) : geom(nGeo), topo(nTopo) {};
        ~Maillage(){};

        void zero();
        void translate(const Point3f&);
        void rotate(const Mat&);
        Maillage cube(const Point3f &, const Point3f &);
        Maillage cylinder(const Point3f &, const Point3f &, float );

        void loadFromOBJ(const string&);
        void writeIntoOBJ(const string&);

        //void box(float, float, float);
        void cone(const Point3f&, float, const Point3f&);
        void cone(const Point3f&, float, float);
        Maillage cylinder(const Point3f&, float, float);
        void sphere(const Point3f&, float);
        void torus(const Point3f&, float, float);
};
#endif
