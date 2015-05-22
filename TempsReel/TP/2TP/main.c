#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

unsigned int compteur1;
unsigned int compteur2;

int stop;

void * incrementeur1 (void * adress){

	char * ad = (char*) adress;
	while(!stop){
		(*ad)++;
		compteur1++;
	}
	pthread_exit(NULL);

}
void * incrementeur2 (void * adress){

	char * ad = (char*) adress;
	while(!stop){
		(*ad)++;
		compteur2++;
	}
	pthread_exit(NULL);

}

int main(int argc, char ** argv){

	printf("Lancement du programme\n");
	pthread_t t1, t2;

	FILE * fic = fopen("data.txt", "w");
	unsigned char addr[513];
	int i;
	for(i = 0; i < 513; i++){
		addr[i] = 0;
	}

	char* start;
	uintptr_t start_addr;
	
	printf("Récupération des addresses\n");
	for(i = 0; i < 513; i++){

		start_addr = (uintptr_t)(addr + i);
		if((start_addr) %256 == 0){
			start = addr + i;
			break;
		}
	}
	int err;

	for(i = 0; i <= 128; i++){
	
		compteur1 = 0;
		compteur2 = 0;
		stop = 0;
		
		pthread_create(&t1, NULL, incrementeur1, (void *)start);
		pthread_create(&t2, NULL, incrementeur2, (void *)(start + i));
		
		sleep(1);
		stop = 1;

		printf("Affichage pour écart de %d \t: Thread 1 = %d\t Thread 2 = %d\n", i, compteur1, compteur2);
		fprintf(fic, "%d %d %d\n", i, compteur1, compteur2);

		pthread_join(t2, NULL);
		pthread_join(t1, NULL);

	}
	fclose(fic);

	return EXIT_SUCCESS;
}
