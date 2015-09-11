#include "outils.hpp"
#include "terrain.hpp"
#include "tree.h"

using namespace std;
using namespace cv;

Terrain::Terrain(float n, float m, float taille): x(n), y(m), size(taille){

    this->pasX = x/size;
    this->pasY = y/size;
    cout << "pas : " << pasX << " " << pasY << endl;

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

Terrain::Terrain(float sample, string filename){

    Mat image;
    image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
    this->x = image.rows * sample;
    this->y = image.cols * sample;
    this->size = image.rows;

    cout << "pixel : " << image.at<char>(12, 34)/5 << endl;

    for(float i = 0; i < size; i++){
        for(float j = 0; j < image.cols; j++){
            Point3f k(i + sample, image.at<char>(i, j)/80, j + sample);
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
            geom[i].y +=  15.0/(2 * k + 1) *
                    smooth_noise(x * (k+3)/2, y * (k+3)/2);
        }
    }

}

void Terrain::addDoubleNoise(){

    for(int i = 0; i < geom.size(); i++){
        for(int k = 0; k < 10; k+=2){
            double x = geom[i].x/20;
            double y =  geom[i].z/20;
            geom[i].y +=  5/pow(2, k) * smooth_noise(x * (2 * k+3), y * (2 * k+3));
        }
    }
}

void Terrain::addWeirdNoise(){

    for(int i = 0; i < geom.size(); i++){
        for(int k = 0; k < 5; k++){

            double x = geom[i].x/20;
            double y =  geom[i].z/20;
            geom[i].y +=
                   montee((geom[i].y + 20)/40) * 5/pow(2, k) *
                    smooth_noise(x * (2 * k+3), y * (2 * k+3));

        }
    }
}

 void Terrain::addSeuil(double s){
    if (s >= -20 && s <= 20){

        for(int i = 0; i < geom.size(); i ++){
            double t = geom[i].y;
            if(t > s + smooth_noise(t, s)){
                geom[i].y -= 2 * (t - s);
            }
        }
    }
 }

 void Terrain::addSeuilBruite(double s){
    if (s >= -20 && s <= 20){

        for(int i = 0; i < geom.size(); i ++){
            double t = geom[i].y;
            if(t > s - smooth_noise(t, s) && t < s + smooth_noise(t, s))
                geom[i].y += 2 * smooth_noise(s, t);
            if(t >= s + smooth_noise(t, s)){
                geom[i].y -= 2 * (t - s);
            }
        }
    }
}


bool Terrain::isViable(Point3f * o){

    Point3f a, b, c, d, p0, p1;
    Mat n, m, normale;

    vector<Point3f>::const_iterator it ;



    printf("Test de isViable\n");

    int indX = (int)(o->x/pasX) % (int)size;
    int indY = (int)(o->z/pasY) % (int)size;

    if(geom.size() < ((indX + 1) * size + indY + 1)){
        d = geom[indX * size + indY];
        c = geom[indX * size + indY - 1];
        b = geom[(indX - 1) * size + indY];
        a = geom[(indX - 1) * size + indY - 1];
        printf("1\n");
    }else{
        a = geom[indX * size + indY];
        b = geom[indX * size + indY + 1];
        c = geom[(indX + 1) * size + indY];
        d = geom[(indX +1) * size + indY + 1];
        printf("2\n");
    }

    *o = Point3f(o->x, a.y, o->z);
    double distAP = cv::norm(a - *o);

    *o = Point3f(o->x, d.y, o->z);
    double distDP = cv::norm(d - *o);

    if(distAP > distDP){
        p1 = highest(d, b, c);
        p0 = lowest(d, b, c);
    }else{
        p0 = lowest(a, b, c);
        p1 = highest(a, b, c);
    }

    o->y = lerp(p0.x, p0.y, p1.x, p1.y, o->x);
    normale = Mat(p0).cross(Mat(p1));

    return (o->y < 20 );
}

 void Terrain::addTrees(){

     int x, y;
     Point3f o;
     for(int i = 0; i < 100; i++){

        do{
             x = rand() % (int)this->x;
             y = rand() % (int)this->y;
         }while(x > this->x - this->pasX && y > this->y - this->pasY);
        o = Point3f(x, 0, y);
        if(this->isViable(&o)){
            this->flore.push_back(Tree(o,Tree::PLATANE, 2));
        }
     }
 }
