#include <stdio.h>

struct TFractie {

       int nr,
           num;
};

typedef struct TFractie Fractie;

void read(Fractie *f) {

     printf("Numaratorul: ");
     scanf("%d", &f->nr);
     printf("Numitorul: ");
     while(scanf("%d", &f->num) && !f->num) printf("Not Zero Numitor!!");

     simplify(f);

};

void sum(Fractie f1, Fractie f2, Fractie *fs) {

     fs->nr = (f1.nr * f2.num + f2.nr * f1.num );
     fs->num = f1.num * f2.num;
 
     simplify(fs);
     
}

void display(Fractie f) {

     if(f.nr == f.num) printf("%d\n", f.num);

              else
                       printf("%d / %d\n",f.nr, f.num); 
}

int myEuclid(int a, int b) {

     int r;

     while(b) {

          r = a % b;

          a = b;

          b = r; 
     } 

     return a;
}

int  simplify(Fractie *f) {
 
     int gcd = myEuclid(f->nr, f->num);
         f->nr = f->nr / gcd;
         f->num = f->num / gcd; 

     return 1;  
}

int main() {

   Fractie f1, f2, fs;

   read(&f1);   
   read(&f2); 
   display(f1);
   display(f2);
   sum(f1, f2, &fs);
   display(fs);

    return(0);
}
