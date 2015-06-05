#include "terrain.hpp"

using namespace std;
using namespace cv;

Terrain::Terrain(float n, float m, float taille): x(n), y(m), size(taille){

	float pasX = x/size, pasY = y/size;

    for(float i = 0; i < x; i += pasX){


		for(float j = 0; j < y; j += pasY){
			 
			Point3f k = Point3f(i, 0, j);
			geom.push_back(k);
		}

	}

	for(int i = 0; i < size - 1; i ++){
		for(int j = 0; j < size - 1; j ++){

			topo.push_back(i * size + j);
			topo.push_back((i+1) * size + j + 1);
			topo.push_back((i+ 1) * size + j);

			topo.push_back(i * size + j);
			topo.push_back(i * size + j + 1);
			topo.push_back((i+1) * size + j + 1);
		}
	}

}

void Terrain::writeIntoOBJ(const string& filename) {

    FILE * f = fopen(filename.c_str(), "w");
    if(f != NULL) {

        vector<Point3f>::const_iterator it ;
        vector<int>::const_iterator it2 ;

        for(it = geom.begin(); it != geom.end(); ++it) {
            fprintf(f, "v %f %f %f\n", it->x, it->y, it->z);
        }
        /*
        for(it = m_normals.begin(); it != m_normals.end(); ++it) {
            fprintf(f, "vn %f %f %f\n", it->x, it->y, it->z);
        }*/
        for(it2 = topo.begin(); it2 != topo.end(); ++it2) {
            fprintf(f, "f %d//", *it2 + 1);
            ++it2 ;
            fprintf(f, " %d//", *it2 + 1);
            ++it2 ;
            fprintf(f, " %d//\n", *it2 + 1);
            /*++it2 ;
            fprintf(f, "%d ", *it2 );
            ++it2 ;
            fprintf(f, "%d//", *it2);
            ++it2 ;
            fprintf(f, "%d\n", *it2);*/
        }
    }
    fclose(f);
}

void Terrain::resethigh(){

    for(int i = 0; i < geom.size() ; i++){
            geom[i].y = 0;
    }
}

void Terrain::addSimplePerlin(){

    for(int i = 0; i < geom.size(); i++){

        geom[i].y = 0;
        for(int k = 0; k < 5; k++){
            double x = geom[i].x/20;
            double y =  geom[i].z/20;
            geom[i].y +=  15.0/pow(2, k) *
                    smooth_noise(x * (k+3)/2, y * (k+3)/2);
        }
    }

}

void Terrain::addDoubleNoise(){

    for(int i = 0; i < geom.size(); i++){
        for(int k = 0; k < 10; k+=2){
            double x = geom[i].x/20;
            double y =  geom[i].z/20;
            geom[i].y +=  7/pow(3, k) * smooth_noise(x * (k+3)/3, y * (k+1));
        }
    }
}

void Terrain::addWeirdNoise(){

    for(int i = 0; i < geom.size(); i++){
        for(int k = 0; k < 5; k++){

            double x = geom[i].x/20;
            double y =  geom[i].z/20;
            geom[i].y +=
                   montee((int)geom[i].y % 1) *
                   smooth_noise(x + k*2, y + k*2 );
        }
    }
}
 void Terrain::addSeuil(double s){
    if (s >= -20 && s <= 20){

        for(int i = 0; i < geom.size(); i ++){
            double t = geom[i].y;
            if(t > s){
                geom[i].y -= 2 * (t - s);
            }
        }
    }
 }
