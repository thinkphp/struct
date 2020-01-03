#include <stdio.h>

struct TPoint {
	double x,
	       y;
};

typedef struct TPoint TPoint;

int main() {

	TPoint P[3];

	int i;

	for(i = 0; i < 3; ++i) {

		printf("Point No. %d (Abs and Ord) -> ", i + 1);

		scanf("%lf %lf", &P[i].x, &P[i].y); 
	} 

	if(P[0].x == P[1].x || P[1].x == P[2].x) {

	if(P[0].x == P[2].x) {

            printf("%s\n", "The points are collinear!");

	} else {

		    printf("%s\n", "The points are not collinear!");

	} 

	} else if( (P[0].y - P[1].y) / (P[0].x - P[1].x) == (P[1].y - P[2].y)/(P[1].x - P[2].x) ) {

		    printf("%s\n", "The points are collinear!");

	} else {

      printf("%s\n", "The points are not collinear!");
	}

	return(0);
}