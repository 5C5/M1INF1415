#include "outils.h"
long ecart(struct timespec left, struct timespec right){

	return ((left.tv_sec - right.tv_sec)* pow(10, 6) + (left.tv_nsec - right.tv_nsec)/1000);
}
