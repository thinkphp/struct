#include <stdio.h>
#define FIN "peytolake.in"
#define size 500

struct Human {

	   char firstname[30],
	        secondname[30],
	        company[30];
	   int salary;
};

typedef struct Human Employee;

void b_s(Employee *p, int n) {

     int finished = 0,

         swapped, 

         count = n - 1, 	

         i;

    while( !finished ) {

     	    swapped = 0;  

            for(i = 0; i < count; ++i) {

            	if(p[i].salary > p[i+1].salary) {

                   Employee holder = p[i];

                            p[i] = p[i+1];

                            p[i+1] = holder;

                            swapped = 1; 
            	}
            }  

            if(swapped) count--; else finished = 1; 
     }     
};

void c_s(Employee *emp, int count) {

	 float shrinkFactor = 1.3;

	 int swapped;

	 int gap = count, 

	     i;

	while(gap > 0 || swapped ) {

	 	   swapped = 0;

	 	   if(gap > 0) gap = gap * 10 / 30;

	 	   for(i = 0; (i + gap) < count - 1; ++i) {

	 	   	   if(emp[i].salary > emp[i+1].salary) {

	 	   	   	  Employee holder = emp[i];

	 	   	   	           emp[i] = emp[i+1];

	 	   	   	           emp[i+1] = holder;

	 	   	   	           swapped = 1;  
	 	   	   }
	 	   }
	 }

};

int _strcmp(const char *x, const char *y) {

    while(*x) {

    	  if(*x != *y) break;

    	  x++; y++; //move to the next pair of characters 
    }

    return (const unsigned char)*x - (const unsigned char)*y;
}

void select(Employee emp[size], int count, char name[30], char key[30]) {            

      printf("SELECT * FROM {table} WHERE %s = %s\n", name, key); 

      for (int i = 0; i < count; ++i)

           if(_strcmp(emp[i].company, key) == 0) {

           	         printf("%s %s\n", emp[i].firstname,  emp[i].secondname);
           }      
};

void selectAll(Employee *emp, int count) {

	     printf("-----\n%s", "My Database: (#ID, first name, second name, company, salary): \n\n"); 

         for (int i = 0; i < count; ++i) 

    	 printf("%d. %s %s %s %d\n", (i + 1), emp[i].firstname, emp[i].secondname, emp[i].company, emp[i].salary); 

    	 printf("-----\n");
};

int main() {

    int count, 
        i;

	Employee emp[ size ];

	freopen(FIN, "r", stdin);

	scanf("%d", &count);
	
	for (int i = 0; i < count; ++i)
	
		scanf("%s %s %s %d", emp[i].firstname, emp[i].secondname, emp[i].company, &emp[i].salary); 
	    
    c_s(emp, count);

    selectAll(emp, count);
    
    select(emp, count, "company", "Google");    	

    return(0);
}; 