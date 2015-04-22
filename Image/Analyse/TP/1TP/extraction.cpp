#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string.h>
#include <iostream>
#include <math.h>


using namespace cv;
using namespace std;


Vec3b traitement(Vec3b a, Vec3b b, int e){
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
		result=b;
		//cout << "Test d entree dans la copie de l image" << endl;
	}
	else{
		result=Vec3b(0,255,0);
	}

	return result;
	
}

Mat traitement(Mat a,Mat b, int e){
	Mat resu(a.rows,a.cols,a.type());
	for(int i=0; i<a.rows;i++){
		for(int j=0; j<a.cols;j++){
			resu.at<Vec3b>(i,j)=traitement(a.at<Vec3b>(i,j),b.at<Vec3b>(i,j),e);
		}
	}

	return resu;
}

int main(int argc, char ** argv){

	string filename = String(argv[1]);
	VideoCapture film(filename);

	Mat frame, bg, obj, green;
	//green = Mat::zeros(frame.rows, frame.cols);
	char key;

	namedWindow("Image normale", 1);
	namedWindow("Objet extrait", 1);

	film >> bg;
	if(bg.empty()){
		return EXIT_FAILURE;
	}
	//bg = Mat(frame);
	film >>frame;
	while(key != 'q' && !frame.empty()){
		

		obj = traitement(bg,frame, 50) ;
		imshow("Image normale", frame);
		imshow("Objet extrait", obj);

		key = (char)waitKey(30);
		while(key != 'g' && key != 'q'){
			key = (char)waitKey(30);
		}
		film >> frame;
	}

	return EXIT_SUCCESS;
}
