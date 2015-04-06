#include "td.hpp"

using namespace std;
using namespace cv;

#define PI (3.141592653589793)

void Maillage::translate(const Point3f &t){
	for(int i = 0; i < geom.size(); i++){
		geom[i]+= t;
	}
}
void Maillage::rotate(const Mat &m){
	for(int i = 0; i < geom.size(); i ++){
        Mat tmp = Mat(geom[i]);
        tmp = tmp * m;
        geom[i] = Point3f(tmp);
	}
}

Maillage Maillage::cube(const Point3f &a, const Point3f &b){

    vector<Point3f> v;
    vector<int> t;

    v.push_back(Point3f(a.x, a.y, a.z));
	v.push_back(Point3f(b.x, a.y, a.z));
	v.push_back(Point3f(a.x, b.y, a.z));
	v.push_back(Point3f(b.x, b.y, a.z));
	v.push_back(Point3f(a.x, a.y, b.y));
	v.push_back(Point3f(b.x, a.y, b.z));
	v.push_back(Point3f(a.x, b.y, b.z));
	v.push_back(Point3f(b.x, b.y, b.y));

	t.push_back(0);
	t.push_back(2);
	t.push_back(3);

	t.push_back(0);
	t.push_back(3);
	t.push_back(1);

	t.push_back(0);
	t.push_back(5);
	t.push_back(4);

	t.push_back(0);
	t.push_back(1);
	t.push_back(5);

	t.push_back(5);
	t.push_back(1);
	t.push_back(3);

	t.push_back(5);
	t.push_back(3);
	t.push_back(7);
	
	t.push_back(2);
	t.push_back(7);
	t.push_back(3);

	t.push_back(2);
	t.push_back(6);
	t.push_back(7);

	t.push_back(4);
	t.push_back(7);
	t.push_back(6);

	t.push_back(4);
	t.push_back(5);
	t.push_back(7);
	
	t.push_back(0);
	t.push_back(4);
	t.push_back(6);
	
	t.push_back(0);
	t.push_back(6);
	t.push_back(2);

    Maillage m = Maillage(v, t);
    return m;
}

void Maillage::writeIntoOBJ(const string& filename) {

    FILE * f = fopen(filename.c_str(), "w");
    if(f != NULL) {

        vector<Point3f>::const_iterator it ;
        vector<int>::const_iterator it2 ;

        for(it = geom.begin(); it != geom.end(); ++it) {
            fprintf(f, "v %f %f %f\n", it->x, it->y, it->z);
        }
        /*
        for(it = m_normals.begin(); it != m_normals.end(); ++it) {
            fprintf(f, "vn %f %f %f\n", it->x(), it->y(), it->z());
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

Maillage Maillage::cylinder(const Point3f &c, float h, float r){

	vector<Point3f> g;
	vector<int> t;
	
}

Maillage Maillage::cylinder(const Point3f &a, const Point3f &b, float r){

	vector<Point3f> g;
	vector<int> t;

	int n = 500;

	Point3f i, j, k, orth;
	k = (b - a);
	k.x /= norm(b-a);
	k.y /= norm(b-a);
	k.z /= norm(b-a);

	orth = Point3f(-k.y, k.x, 0);
	i = orth;
	i.x /= norm(orth);
	i.y /= norm(orth);
	i.z /= norm(orth);
	j = k.cross(i);

	int s;
	for(s = 0; s < n; s++){
		g.push_back(Point3f(a + r * (cos((2 *PI * s)/n)) * i + r * (sin((2 * PI * s)/n)) * j));
	}

	for(s = n; s < (2 * n); s++){
		g.push_back(Point3f(b + r * (cos((2 *PI * s)/n)) * i + r * (sin((2 * PI * s)/n)) * j));
	}

	g.push_back(a);
	g.push_back(b);

	for(s = 0; s < n; s++){
		
		t.push_back((s+1)%n);	
		t.push_back(s);	
		t.push_back(2 * n);
	}
	for(s = 0; s < n; s++){

		t.push_back(n + s );
		t.push_back(n + (s+1)%n);
		t.push_back(2 * n + 1);
	}

	for(s = 0; s < n; s++){

		t.push_back(s);
		t.push_back((s+1)%n);
		t.push_back(n + (s+1)%n);
	}
	for(s = 0; s < n; s++){

		t.push_back(s);
		t.push_back(n + (s+1)%n);
		t.push_back(n + s);
	}

	return Maillage(g, t);

}

int main(int argc, char **argv){


    vector<Point3f> v;
    vector<int> t;
    
	Maillage m, cy;
	m = Maillage(v, t);

    
	Point3f a = Point3f(0, 0, 0);
    Point3f b = Point3f(5, 5, 5);

    m = m.cube(a, b);
	cy = cy.cylinder(a, b, 5);
    m.writeIntoOBJ("cube.obj");
	cy.writeIntoOBJ("cylindre.obj");

    return EXIT_SUCCESS;
}
