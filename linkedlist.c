#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define FIN "peytolake.in"
#define FOUT "peytolake.out"

struct Employee {

	   char firstname[30];
	   char secondname[30];
	   char company[30];
	   int salary;
};

typedef struct Employee Employee;

struct TNode {

	   Employee data;
	   struct TNode *next;
};

typedef struct TNode Node;

Node *head = NULL;

void addedLinkedList(Employee data) {

	 Node *c;

	 if( head == NULL ) {

         c = (Node*)malloc(sizeof(Node));

         c->data = data;

         c->next = NULL;

         head = c;

	 } else {

	 	 c = (Node*)malloc(sizeof(Node));

	 	 c->data = data;

	 	 c->next = head;

	 	 head = c;
	 }
}

void removeNode(char key[30]) {

     Node *c;

     if(strcmp( head->data.company , key) == 0)  {

     	    printf("Deleted: %s\n", head->data.firstname);  
 
            c = head;

            head = head->next;

            free(c);

     } else {

     	     Node *ptr, *v;

     	     ptr = head;

     	     while( strcmp(ptr->next->data.company, key) != 0 )  ptr = ptr->next;

     	         printf("Deleted: %s\n", ptr->next->data.firstname);  

     	         v = ptr->next;

     	         ptr->next = v->next;

     	         free(v); 
     }
}

void display(Node *p) {

     int k = 1;

     printf("\n ---\n");

     while(p) {

     	   printf("%d. %s %s %s %d\n",k , p->data.firstname, p->data.secondname, p->data.company, p->data.salary);

           p = p->next; k++;
     }

     printf("\n ---\n");
}

void display_to_file(Node *p) {

	 FILE *fp = fopen(FOUT, "a");

     int k = 1;

     fprintf(fp, "\n ---\n");

     while(p) {

     	   fprintf(fp, "%d. %s %s %s %d\n",k , p->data.firstname, p->data.secondname, p->data.company, p->data.salary);

           p = p->next; k++;
     }

     fprintf(fp, "---\n");

     fclose(fp);
}

void bubble_sort() {

     Node *c;

     int swapped;     
    
      do {

        swapped = 0;

        c = head;

        while(c->next) {

              if( strcmp(c->data.firstname, c->next->data.firstname) > 0) {

                          Employee holder = c->data;

              	          c->data = c->next->data;

              	          c->next->data = holder;

              	          swapped = 1;        
              }
              
              c = c->next;  
        }      

        } while(swapped);

}

int main() {

    int i, n;

    Employee x[100];

    freopen(FIN, "r", stdin);

    scanf("%d", &n);

    for(i = 0; i < n; ++i) 

        scanf("%s %s %s %d", x[i].firstname, x[i].secondname, x[i].company, &x[i].salary),

        addedLinkedList(x[i]);

    display(head);    

    display_to_file(head);

    removeNode("Twitter");

    removeNode("Twitter");
    
    display(head);

    display_to_file(head);

    bubble_sort();

    display(head);

    display_to_file(head);
   
	return(0);
}