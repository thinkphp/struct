#include <stdio.h>
#define SIZE 1000

struct TSet {

	unsigned int n;
	int arr[SIZE];
};

typedef struct TSet Set;

void read(Set *p) {

     int i;

     printf("%s\n", "Number of elements -> ");

     scanf("%d", &p->n);

     for (int i = 0; i < p->n; ++i)
     {
     	 scanf("%d", &p->arr[i]);
     }
}

int belongs(Set S, int elem) {

    int i;  

    for(i = 0; i < S.n; ++i) 

    	if(S.arr[i] == elem) return 1;

    return 0;
}

void displaySet(Set M) {

     int i;

     printf("{");

     for(i = 0; i < M.n; ++i) {

     	 printf("%d ", M.arr[i]);
     }

     printf("}\n");
}

int main(int argc, char const *argv[])
{
	Set A, B, 
	    I, R, D;
	    int i;	    
 
	    read(&A);
	    read(&B);

	    I.n = 0; D.n = 0; R = B; 

	    for(i = 0; i < A.n; ++i) {

	    	if(belongs(B, A.arr[i])) I.arr[I.n++] = A.arr[i];

	    	       else { 
	    	       	      D.arr[D.n++] = A.arr[i]; 
	    	       	      R.arr[R.n++] = A.arr[i]; 
	    	       	     }
	    }

        displaySet(I);
	    displaySet(D);
	    displaySet(R);

	return 0;
}
