#include "terrain.hpp"

int main(int argc, char ** argv){

    //Terrain t(900.0, 900.0, 600.0);
    //Terrain n(900.0, 900.0, 600.0);
    Terrain m(900.0, 900.0, 600.0);
    //t.writeIntoOBJ("terrain.obj");
    //t.addSimplePerlin();
    //t.writeIntoOBJ("noise.obj");
    //n.addSimplePerlin();
    //n.addDoubleNoise();
    //n.writeIntoOBJ("double.obj");
    //t.resethigh();
    m.addSimplePerlin();
    m.addWeirdNoise();
    m.writeIntoOBJ("weird.obj");
    m.addSeuil(7);
    m.writeIntoOBJ("seuil.obj");
	return EXIT_SUCCESS;
}
