#include "terrain.hpp"
#include "td.hpp"
int main(int argc, char ** argv){

    Terrain a(1200, 1200, 300);

    a.addSimplePerlin();
    a.writeIntoOBJ("noise.obj");
    a.addDoubleNoise();
    a.writeIntoOBJ("double.obj");
    a.addWeirdNoise();
    a.writeIntoOBJ("weird.obj");
    a.addSeuil(8);
    a.writeIntoOBJ("seuil.obj");
    a.resethigh();
    a.addSeuilBruite(8);
    a.writeIntoOBJ("seuilb.obj");
    return EXIT_SUCCESS;
}
