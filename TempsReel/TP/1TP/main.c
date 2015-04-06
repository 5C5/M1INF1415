#include "outils.h"

#define NB_CALL 10000


long toCall(int nbcall, int dt){

	struct timespec callTime;
	static struct timespec t0;
	clock_gettime(CLOCK_MONOTONIC, &callTime);
	if(nbcall == 0){
		t0 = callTime;
	}
	return (ecart(callTime, t0) - nbcall * dt);
}

int main(int argc, char ** argv){

	int option, nbcall = 0, dt, sub;
	struct timespec time, t0;
	int tab[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while((option = getopt(argc, argv, "d:")) != -1){
		
		switch(option){

			case 'd':
				dt = atoi(optarg);
				break;
		}
	}
	dt = 100;

	clock_gettime(CLOCK_MONOTONIC, &t0);
	do{
		
		clock_gettime(CLOCK_MONOTONIC, &time);

		if(ecart(time, t0) - nbcall * dt >= 0){
			sub = toCall(nbcall, dt);
			
			if(sub < 0)
				tab[6 - (int)fmin(log10(-sub), 6)]++;
			else if(sub == 0)
				tab[6]++;
			else
				tab[6 + (int)fmin(log10(sub), 6)]++;
			nbcall++;
		}

	}while(nbcall < NB_CALL);

	int i;
	for(i = 0; i < 13; i ++){

		if(i == 2)
			fprintf(stdout, "Avance :\t10^%d:\t%d\n", (int)fabs(i-6), tab[i]);
		else if(i==6)
			fprintf(stdout, "Exact :\t\t\t%d\n", tab[i] );
		else if(i == 10)
			fprintf(stdout, "Retard :\t10^%d:\t%d\n", (int)fabs(i-6), tab[i] );
		if(i !=6 && i !=2 && i != 10)
			fprintf(stdout, "\t\t10^%d:\t%d\n", (int)fabs(i-6), tab[i] );
	}
	return EXIT_SUCCESS;
}
