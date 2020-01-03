/*
 * Author     :  Adrian Statescu <mergesortv@gmail.com>
 * Description:  Complex Numbers a + ib + c + id 
 *               Read, Display, Sum, Prod, Div
 */
#include <stdio.h>
#define FIN "complex.in"
#define FOUT "complex.out"

struct TComplex {
       int real,
           imag;
};

typedef struct TComplex Complex;

void read(Complex *c) {

     printf("%s\n", "Real:");
     scanf("%d", &c->real); 

     printf("%s\n", "Imag:");
     scanf("%d", &c->imag); 
};

void display(Complex c) {

     printf("%d + i%d\n", c.real, c.imag);
};

void display_file(char *s, Complex c) {     

     printf("%s -> %d + i%d\n", s, c.real, c.imag);
};

void complex_sum(Complex c1, Complex c2, Complex *sum) {
	
     sum->real = c1.real + c2.real;  
     sum->imag = c1.imag + c2.imag;
};


void complex_prod(Complex c1, Complex c2, Complex *prod) {
	
     prod->real = c1.real * c2.real - c1.imag * c2.imag;
     prod->imag = c1.real * c2.imag + c2.imag * c1.imag;
};

void complex_div(Complex c1, Complex c2, Complex *div) {

	 int d = c1.real * c1.real + c2.imag * c2.imag;
     div->real = (c1.real * c2.real) / d;
     div->imag = (c1.real * c2.imag + c2.real * c1.real) / d;
};


int main(int argc, char const *argv[])
{
    Complex c1, //first number
            c2, //second number
            cs, //sum of two numbers
            cp, //multiply
            cd, //division
            cc; //conjugate

	read(&c1); 
	read(&c2);
	display(c1);
	display(c2);
    complex_sum(c1, c2, &cs);
    complex_prod(c1, c2, &cp);
    complex_div(c1, c2, &cd);
    display(cs);
    display(cp);
    display(cd);
    freopen(FOUT, "w", stdout);
    display_file("First Number", c1); 
    display_file("Second Number", c2); 
    display_file("Sum", cs); 
    display_file("Prod", cp); 
    display_file("Div", cd); 
			
	return 0;
}
