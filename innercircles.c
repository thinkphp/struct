#include <stdio.h>
#include <math.h>
#define MAX 100

struct TPoint {

       float x, 
             y;
};

typedef struct TPoint Point;

struct TCircle {

       Point O;
       float R;
};

typedef struct TCircle Circle;

float distance(Point p1, Point p2) {

	  return sqrt((p1.x - p2.x) * (p1.y - p2.y));
}

int apartine(Circle C, Point p) {

    return (float)distance(C.O, p) < C.R;
}

int main(int argc, char const *argv[])
{
	
	Circle C[ MAX ]; 
	Point P;
	int i, count;

    printf("%s", "How many Circles? N = ");
    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
     {
     	 printf("Circle No. %d\n", i + 1);

     	 scanf("%f %f %f", &C[i].O.x, &C[i].O.y, &C[i].R);
     } 

     printf("%s", "Point(x,y) = ");

     scanf("%f %f", &P.x, &P.y);

    for (int i = 0; i < count; ++i) {
 
    	 if(apartine(C[i], P)) printf("Circle(%3.3f %3.3f %f)\n", C[i].O.x, C[i].O.y, C[i].R);
    }

	return 0;
}