#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/nonfree/features2d.hpp"


#ifndef OUTILS_H
#define OUTILS_H

using namespace std;
using namespace cv;

#define B 0x100
#define BM 0xff

#define N 0x1000
#define NP 12  
#define NM 0xfff

/*
//Code de Ken PERLIN : ne compile pas tel quel
//, et ne fonctionne pas en réparant les erreurs de compilation
static int p[B + B + 2];
static float g3[B + B + 2][3];
static float g2[B + B + 2][2];
static float g1[B + B + 2];
static int start = 1;


static void init(void);
double noise1(double);
float noise2(float *);
float noise3(float *);
static void normalize2(float *);
static void normalize3(float *);
*/
double noise(int);
double noise(int, int);
double cubic_interpolate(double, double, double, double, double);
double smooth_noise_firstdim(int, int, double);
double smooth_noise(double, double);
double smooth_noiseABS(double, double);
void test();

double lerp(double, double, double, double, double);
double montee(double);
Point3f highest(Point3f, Point3f, Point3f);
Point3f lowest(Point3f, Point3f, Point3f);
#endif
