#include "terrain.hpp"

int main(int argc, char ** argv){

    //Terrain t(900.0, 900.0, 600.0);
    Terrain n(900.0, 900.0, 600.0);
    Terrain m(900.0, 900.0, 600.0);
    n.writeIntoOBJ("terrain.obj");
    //t.addSimplePerlin();
    //t.writeIntoOBJ("noise.obj");
    n.addSimplePerlin();
    n.addDoubleNoise();
    n.writeIntoOBJ("double.obj");
    m.addSimplePerlin();
    //m.addWeirdNoise();
    //m.writeIntoOBJ("weird.obj");
    //m.addSeuil(9);
    //m.writeIntoOBJ("seuil.obj");
    m.addSeuilBruite(9);
    m.writeIntoOBJ("seuib.obj");
	return EXIT_SUCCESS;
}
