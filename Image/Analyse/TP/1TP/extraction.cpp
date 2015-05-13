#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;


bool bordEcrans(int x, int y, int maxX, int maxY, int ecart){

	if(x < ecart || y < ecart || x > (maxX - ecart) || y > (maxY - ecart))
		return true;
	return false;
}

/*
 *
 */
Mat filtrePerso(Mat a, Vec3b valeur, int seuil){
	
	Mat resu = Mat(a.size(), a.type());
	int temp = 0;

	for(int i = 0; i < a.rows - 0; i++){
		for(int j = 0; j < a.cols - 0; j++){

			temp = 0;
			if(a.at<Vec3b>(i, j) != valeur){
				if(!bordEcrans(i, j, a.rows -1, a.cols -1 , 2)){

					for(int k = i -2; k < i + 2; k ++){
						for(int l = j - 2; l < j + 2; l++){
							
							if(a.at<Vec3b>(k, l) != valeur)
								temp++;
						}
					}
					if(temp < seuil)
						resu.at<Vec3b>(i, j) = valeur;
					else
						resu.at<Vec3b>(i, j) = a.at<Vec3b>(i, j);
						//*/
				}
			}
			else{
				resu.at<Vec3b>(i, j) = valeur;
			}
		}
	}
	return resu;
}

/*
 * Méthodes prenant deux vecteurs en paramètre, créant un troisième avec comme couleur la moyenne/différence des différences entre les deux premiers
 * @params vec2b a et c, deux "pixels"
 * @return vec2b , vecteur résultat de la différence
 */
Vec3b difference(Vec3b a, Vec3b b){
	
	Vec3b result;
	//int color = (abs((int)a[0] - (int)b[0]) + abs((int)a[1] - (int)b[1]) + abs((int)a[2] - (int)b[2]))/3;
	int color = max(max(abs((int)a[0] - (int)b[0]), abs((int)a[1] - (int)b[1])), abs((int)a[2] - (int)b[2]));
	result= Vec3b(color, color, color);

	return result;
	
}

/*
 * Méthodes prenant deux matrices en paramètres et renvoyant una matrice après avoir passé chaque pixel des deux premières par Vec3b difference(Vec3b, Vec3b)
 */
Mat difference(Mat a,Mat b){

	Mat resu(a.rows,a.cols,a.type());
	for(int i=0; i<a.rows;i++){
		for(int j=0; j<a.cols;j++){
			resu.at<Vec3b>(i,j) = difference(a.at<Vec3b>(i,j), b.at<Vec3b>(i,j));
		}
	}

	return resu;
}

/*
 * Traitement : extrait la différence entre deux points/couleurs
 * @params : trois points, un pour le décor, un pour l'image floutée, et un pour l'image à afficher, un entier pour la différence acceptée
 * @return : un point
 */
Vec3b traitement(Vec3b a, Vec3b b, Vec3b c, int e){
	Vec3b result;
	
	if(abs((int)a[0] - (int)b[0]) >e||abs((int)a[1] - (int)b[1]) >e||abs((int)a[2] - (int)b[2]) >e){
		result=c;
	}
	else{
		result=Vec3b(0,255,0);
	}

	return result;
	
}

/*
 * Traitement : extrait la différence entre deux images
 * @params : Deux matrices à différencier et un entier représentant l'écart de valeur accepté
 * @return : Matrice contenant la différence entre les deux matrices en entrées et des points vers pour combler
 */

Mat traitement(Mat a,Mat b, int e){
	Mat temp;
	Size taille(3, 3);
	GaussianBlur(b, temp, taille, 0, 0);
	Mat resu(a.rows,a.cols,a.type());
	for(int i=0; i<a.rows;i++){
		for(int j=0; j<a.cols;j++){
			resu.at<Vec3b>(i,j) = traitement(a.at<Vec3b>(i,j),temp.at<Vec3b>(i,j), b.at<Vec3b>(i, j), e);
		}
	}

	return resu;
}

Mat doThings(Mat &a){
	

	Mat hls;
	Mat splitted[3];
	Mat res;

	cvtColor(a, hls, CV_BGR2HLS);
	
	for(int i=0; i<a.rows;i++){
		for(int j=0; j<a.cols;j++){
			Vec3b hlsij=hls.at<Vec3b>(i,j);
			hlsij[1]=255;
		}
	}


	cvtColor(hls, res, CV_HLS2BGR);
	
	return res;
}


/*
 * Programme principal
 * @param : nom de la vidéo à afficher
 */
int main(int argc, char ** argv){

	string filename = String(argv[1]);
	int device = -1;
	int compteur = 0, decaleur;
	if(filename.length() == 1){
		device = atoi(argv[1]);
		printf("Utilisation d'une caméra\n");
	}
	VideoCapture film;
	printf("Valeur de device : %d\n", device);
	if(device > 0)
		film = VideoCapture(--device);
	else
		film = VideoCapture(filename);

	Mat frame, bg, obj, bgflou, diff, hist, diffhist, tmp;
	char key;

	namedWindow("Image normale", 1);
	namedWindow("objet extrait", 1);

	//Récupération du décor
	film >> bg;
	//Floutage du décor
	Size taille(11, 11);
	GaussianBlur(bg, bgflou, taille, 0, 0);
	
	if(bg.empty()){
		return EXIT_FAILURE;
	}

	//récupération de la première image
	if(film.isOpened())
		film >>frame;
	else
		return EXIT_FAILURE;

	//Boucle de traitement
	//
	hist=bg.clone();
	while(key != 'q' && !frame.empty()){
		
		//extraction dans obj de la différence entre bg et frame
		obj = traitement(bgflou,frame, 50) ;
		
		diffhist = difference(hist, frame);
		diff = difference(bg, frame);
		
		//Affichage des différentes images
		imshow("Image normale", frame);
		imshow("objet extrait", obj);
		
		imshow("Différence background in grayscale", diff);
		imshow("Current Test", diffhist);

		key = (char)waitKey(30);
		
		while(key != 'g' && key != 'q' && device < 1){
			key = (char)waitKey(30);
		}//*/

		compteur ++;

		if(film.isOpened()){
			
			/*if(compteur%10 == 0){
				tmp = obj.clone();
				decaleur = compteur;
			}
			if(compteur == decaleur + 10)
				hist = tmp.clone();//*/
			hist = frame.clone();
			film >>frame;
		}
		else
			return EXIT_FAILURE;
	}

	film.release();

	return EXIT_SUCCESS;
}
