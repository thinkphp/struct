#include <stdio.h>
#include <math.h>
#define FIN "points.in"

struct TPoint {
	double x, //abscise
	       y; //ordonate
};

typedef struct TPoint Point;

double distance(Point P1, Point P2) {

       return sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));
}

void readPoint(Point *P) {

    printf("%s", "(abs, ord) ->");
    scanf("%lf %lf", &P->x, &P->y);
    printf("%lf %lf\n", P->x, P->y);
}

int main(int argc, char const *argv[])
{
    Point P0, 
          P1, 
          P; 	
    int i, n;
    double dist, d;        
    freopen(FIN, "r", stdin);
    
    printf("P0 ");
    readPoint(&P0);

    printf("%s", "How many numbers ? ->\n");
    scanf("%d", &n);
    printf("%d points\n", n);

    printf("First Point ->\n"); 
    readPoint(&P1);

    dist = distance(P0, P1);

    for(i = 2; i <= n; ++i) {

    	printf("Point %d -> \n", i); 

    	readPoint(&P);

    	d = distance(P0, P);

    	if(d < dist) {

    	   dist = d;
    	   P1 = P; 	
    	}
    }

    printf("\nDistance Minimum %.7lf corresponding to the point (%.4lf, %.4lf)\n", dist, P1.x, P1.y);

	return 0;
}
