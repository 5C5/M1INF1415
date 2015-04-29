#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;

/*
 * Traitement : extrait la différence entre deux points/couleurs
 * @params : trois points, un pour le décor, un pour l'image floutée, et un pour l'image à afficher, un entier pour la différence acceptée
 * @return : un point
 */
Vec3b traitement(Vec3b a, Vec3b b, Vec3b c, int e){
	Vec3b result;
	/*for(int i = 0; i < 3; i ++){
		if(abs(a[i] - b[i]) >e)
			result[i] = b[i];
		else
			result[i] = 0;
	}*/

	//cout << "Affichage de a[0] : " << a[0] << " et de b[0] : " << b[0] << "et la soustraction : " << a[0] - b[0] << endl;
	if(abs((int)a[0] - (int)b[0]) >e||abs((int)a[1] - (int)b[1]) >e||abs((int)a[2] - (int)b[2]) >e){
	//if(a[0] != b[0] || a[1] != b[1] || a[2] != b[2]) {
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
			resu.at<Vec3b>(i,j)=traitement(a.at<Vec3b>(i,j),temp.at<Vec3b>(i,j), temp.at<Vec3b>(i, j), e);
Mat traitement(Mat a,Mat b, int e){
	Mat temp;
	Size taille(3, 3);
	GaussianBlur(b, temp, taille, 0, 0);
	Mat resu(a.rows,a.cols,a.type());
	for(int i=0; i<a.rows;i++){
		for(int j=0; j<a.cols;j++){
			resu.at<Vec3b>(i,j)=traitement(a.at<Vec3b>(i,j),temp.at<Vec3b>(i,j), temp.at<Vec3b>(i, j), e);
		}
	}

	return resu;
}

Mat doThings(Mat &a){
	
	//cout << "types : " << a.type() << " et nbre de cannaux " << a.channels() << endl;

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
	if(filename.length() == 1)
		device = atoi(argv[1]);
	VideoCapture film;
	printf("Valeur de device : %d\n", device);
	if(device > 0)
		film = VideoCapture(--device);
	else
		film = VideoCapture(filename);

	Mat frame, bg, obj, bgflou;
	char key;

	namedWindow("Image normale", 1);
	namedWindow("objet extrait", 1);

	//Récupération du décor
	film >> bg;
	bg = doThings(bg);
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
	while(key != 'q' && !frame.empty()){
		
		frame = doThings(frame);
		//extraction dans obj de la différence entre bg et frame
		obj = traitement(bgflou,frame, 50) ;
		
		//affichage de l'image et de l'obj extrait
		imshow("Image normale", frame);
		imshow("objet extrait", obj);

		key = (char)waitKey(30);
		
		while(key != 'g' && key != 'q' && device < 1){
			key = (char)waitKey(30);
		}//*/

		if(film.isOpened())
			film >>frame;
		else
			return EXIT_FAILURE;
	}

	film.release();

	return EXIT_SUCCESS;
}
