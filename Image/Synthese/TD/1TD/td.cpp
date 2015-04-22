#include "td.hpp"

using namespace std;
using namespace cv;

#define PI (3.141592653589793)

vector<Point3f>& Maillage::getGeom(){
	return geom;
}

vector<int>& Maillage::getTopo(){
	return topo;
}

/*
 * Fonction de nettoyage du maillage
 */
void Maillage::zero(){
	geom.clear();
	topo.clear();
}

/*
 * Fonction de déplacement du maillage
 */
void Maillage::translate(const Point3f &t){
	for(int i = 0; i < geom.size(); i++){
		this->geom[i]+= t;
	}
}

/*
 * Fonction de rotation du Maillage
 */
void Maillage::rotate(const Mat &m){
	for(int i = 0; i < geom.size(); i ++){
        Mat tmp = Mat(geom[i]);
        tmp = tmp * m;
        this->geom[i] = Point3f(tmp);
	}
}

/*
 * Fonction d'ajout d'un Maillage au maillage actuel
 */
void Maillage::merge(Maillage &m){

    vector<Point3f>::const_iterator it ;
    vector<int>::const_iterator it2 ;

    int vertices_number = geom.size() ;
	//printf("Nombre de sommet de base : %d, nbre de sommet à ajouter : %d\n", vertices_number, m.geom.size());
    //int normals_number = m_normals.size() ;
    bool vertex = true ;

    for(it = m.geom.begin(); it != m.geom.end(); ++it) {
		cout << "avant ajout : " << (*it) << endl;
        geom.push_back(*it);
		cout << "apres ajout : " << geom.back() << endl;
    }

    for(it2 = m.topo.begin(); it2 != m.topo.end(); ++it2) {

        topo.push_back((*it2 + vertices_number));
    }
}

/*
 * Fonction de sérialisation du maillage
 */
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


/*
 * Création d'un cube
 */
Maillage Maillage::cube(const Point3f &a, const Point3f &b){

    vector<Point3f> v;
    vector<int> t;

    v.push_back(Point3f(a.x, a.y, a.z));
	v.push_back(Point3f(b.x, a.y, a.z));
	v.push_back(Point3f(a.x, b.y, a.z));
	v.push_back(Point3f(b.x, b.y, a.z));
	v.push_back(Point3f(a.x, a.y, b.z));
	v.push_back(Point3f(b.x, a.y, b.z));
	v.push_back(Point3f(a.x, b.y, b.z));
	v.push_back(Point3f(b.x, b.y, b.z));

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

/*
 * Fonction de création d'un cylindre à partir d'un point, d'une hauteur et d'un rayon
 */
Maillage Maillage::cylinder(const Point3f &c, float h, float r){

	Maillage m;
	return m.cylinder(c, Point3f(c.x, c.y, c.z + h), r);
	
}

/* Fonction de création d'un cylindre à partir de deux points et d'une hauteur
 */
Maillage Maillage::cylinder(const Point3f &a, const Point3f &b, float r){

	vector<Point3f> g;
	vector<int> t;

	//cout << "points utilisés : " << a << "et " << endl << b <<endl;
	int n = 500;

	Point3f i, j, k, orth;
	k = (b - a);
	if( norm(b-a)!=0){
		k.x /= norm(b-a);
		k.y /= norm(b-a);
		k.z /= norm(b-a);
	}

	orth = Point3f(-k.y, k.x, 0);
	i = orth;
	if(norm(orth) != 0){
		i.x /= norm(orth);
		i.y /= norm(orth);
		i.z /= norm(orth);
	}
	if(i.x == 0) i.x = 1;
	if(i.y == 0) i.y = 1;
	//if(i.z == 0) i.z = 1;

	j = k.cross(i);
	if(j.x == 0) j.x = 1;
	if(j.y == 0) j.y = 1;
	//if(j.z == 0) j.z = 1;

	int s;
	for(s = 0; s < n; s++){
		g.push_back(Point3f(a + r * (cos((2 *PI * s)/n)) * i + r * (sin((2 * PI * s)/n)) * j));
		cout << "points : " << g.back() << endl;
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

/*
 * Fonction de création d'un Tore, à partir d'un point, du rayon du petit cercle et du rayon du grand cercle
 */
Maillage Maillage::torus(const Point3f & c, float pr, float gr){

	vector<Point3f> geom;
	vector<int> topo;

	Point3f x(1, 0, 0), y(0, 0, 1), z(0, 1, 0);
	Point3f u, v, w;
	int i, j, n = 500, m = 150;

	for(i = 0; i < n; i++){
		
		u = Point3f(cos(i* 2 * PI/n), sin(i * PI * 2/n), 0);
		v = y;
		w = Point3f(-sin(i * 2 * PI/n), cos(i * PI * 2/n), 0);

		for(j = 0; j < m; j++){
			
			geom.push_back(c + pr*(cos(i*2*PI/n)*x + sin(i*2*PI/n)*z) + gr * (cos(j*2*PI/m)*u + sin(j*2*PI/m)*v));
		}

	}
	for(i = 0; i < n; i++){

		for(j = 0; j < m; j++){

			topo.push_back(i *m + j);
			topo.push_back(((i+1)%n)*m+j);
			topo.push_back(((i+1)%n)*m+(j+1)%m);

			topo.push_back(i*m+j);
			topo.push_back(((i+1)%n)*m+(j+1)%m);
			topo.push_back(i*m+(j+1)%m);

		}
	}

	return Maillage(geom, topo);
}

/*
 * Fonction de création d'une sphère à partir d'un point et d'un rayon
 */
Maillage Maillage::sphere(const Point3f& o, float r) {

	int circlePointNb = 500;
	int circleNb = circlePointNb / 2 ;
	float b, a;
	vector<Point3f> geom;
	vector<int> topo;

	for(int i = 0; i <= circleNb; i++) {

		a = -0.5*PI+(float(i)*PI/circleNb);

		for(int j = 0; j < circlePointNb; j++){

			b = float(j)*2*PI/circlePointNb;
			geom.push_back(o + r * Point3f(cos(a)*cos(b), sin(a), cos(a)*sin(b)));
		}
	}


	for(int i = 0; i < circleNb; i++) {

		for(int j = 0; j < circlePointNb; j++){

			topo.push_back((i*circlePointNb)+j);
			topo.push_back( ((i+1)*circlePointNb)+j);
			topo.push_back( ((i+1)*circlePointNb)+(j+1)%circlePointNb);


			topo.push_back((i*circlePointNb)+j);
			topo.push_back(((i+1)*circlePointNb)+(j+1)%circlePointNb);
			topo.push_back((i*circlePointNb)+(j+1)%circlePointNb);
			}

	}
	return Maillage(geom, topo);

}


/*
 * Fonction d'essai divers
 */
Maillage Maillage::test(float minHeight, float maxHeight, float scaleOnTop, float scaleOnBottom){

	vector<Point3f> geom;
	vector<int> topo;
     int min = -10, max = 10 ; // Bornes min et max en x et z

    float pas = 1./5. ;
    int n = (max - min)*(1/pas) + 1 ; // Nombre de sommets entre la borne min et la borne max

    for(float x = min; x <= max; x += pas) {
        for(float z = min; z <= max; z += pas) {

            float y = (1.5 * sin(sqrt(x*x + z*z) * (PI/2) - (PI/2))) / sqrt(1 + x*x + z*z) ;
            geom.push_back(Point3f(x, y, z));
        }
    }

    int i = 0, j = 0 ;
    for(i = 0; i <= n+1; i++) {
        for(j = 0; j <= n+1; j++) {

            topo.push_back((i*(n+1)) + j);
            topo.push_back((i*(n+1)) + (j+1));
            topo.push_back(((i+1)*(n+1)) + j);
            topo.push_back(((i+1)*(n+1)) + j);
            topo.push_back((i*(n+1)) + (j+1));
            topo.push_back(((i+1)*(n+1)) + (j+1));
        }
    }
    return Maillage(geom, topo);
}


Maillage Maillage::temple(Point3f &a, Point3f &b){

	int i, j;
	float ecartY, ecartX, ecartZ;
	ecartX = abs(a.x - b.x);
	ecartY = abs(a.y - b.y);
	ecartZ = abs(a.z - b.z);
	Maillage base, colonne, toit;
	base = base.cube(a, b);

	for(i = 1; i < 8; i++){
		toit.zero();
		toit = toit.cube(Point3f(a.x, a.y, a.z - i), Point3f(b.x, (b.y + i*ecartY/20), b.z - i));
		base.merge(toit);
	}

	cout << endl << endl << endl;
	//base.writeIntoOBJ("temple.obj");
	colonne = colonne.cylinder(Point3f(a.x + 2 * ecartX/20, a.y + 2 * ecartY/20, b.z), Point3f(a.x + ecartX/20, a.y + ecartY/20, b.z + ecartZ*4), ecartX/20);
	base.merge(colonne);
	//cout << "têtes des points de la colonne : " << colonne.getGeom() << endl;
	colonne.writeIntoOBJ("colonne.obj");

	/*for(j = 1; j < 20; j+=18){
		for(i = 1; i < 20; i+=3){
			colonne = colonne.cylinder(Point3f(i, j, 2), 10, 2);
			base.merge(colonne);
			//colonne.zero();
		}
	}*/
	printf("Temple terminé\n");
	base.writeIntoOBJ("temple.obj");
	return base;
}



int main(int argc, char **argv){


    vector<Point3f> v;
    vector<int> t;
    
	Maillage m, cy, to, sp, tp, test;
	m = Maillage(v, t);

    
	Point3f a = Point3f(0, 0, 0);
    Point3f b = Point3f(20, 20, 2);

    m = m.cube(a, b);
	cy = cy.cylinder(a, b, 5);
    m.writeIntoOBJ("cube.obj");
	cy.writeIntoOBJ("cylindre.obj");
	to = to.torus(a, 10, 5);
	to.writeIntoOBJ("torus.obj");
	sp = sp.sphere(a, 5);
	sp.writeIntoOBJ("sphere.obj");

	tp = test.temple(a, b);
	//tp.writeIntoOBJ("temple.obj");
    return EXIT_SUCCESS;
}
