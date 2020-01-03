#include <stdio.h>
#include <math.h>

struct TPoint {
       float x,
             y;
};

typedef struct TPoint Point;

struct TCircle {

	   Point O;
	   float r; 
};

typedef struct TCircle Circle;

int main(int argc, char const *argv[])
{
	Circle C;
	Point P;
	double d;

	printf("%s\n", "Circle -> ");
	scanf("%f %f %f", &C.O.x, &C.O.y, &C.r);

	printf("%s\n", "Point -> ");
	scanf("%f %f", &P.x, &P.y);
	
	d = sqrt((P.x - C.O.x) * (P.x - C.O.x) + (P.y - C.O.y) * (P.y - C.O.y));

	d -= C.r; 

	if( d == 0) {

		printf("%s\n", "The Point is on the board of the Circle."); 

	} else if( d < C.r) {

		printf("%s\n", "The Point is inside of the Circle."); 

    } else if(d > C.r) {

    	printf("%s\n", "The Point is outside of the Circle.");

	}

	return 0;
}