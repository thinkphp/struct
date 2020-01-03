#include <stdio.h>
#include <math.h>

int main() {

	float x, y, r, x0, y0;
	float d;

	printf("Circle O(x,y,r): \n");
	
	scanf("%f %f %f", &x, &y, &r);

    printf("Point(x0,y0)\n");
	scanf("%f %f", &x0, &y0);

	d = sqrt ( (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) );
    
    d = d - r;

    if(d == 0) {

       printf("%s\n", "The point is on the border of the Circle.");

    } else if( d < r) {

       printf("%s\n", "The point is inside the Circle.");  

    } else if(d > r) {

       printf("%s\n", "The point is outside the Circle.");  
    }

	return(0);
}