#include <stdio.h>
#define STACK_MAX 100

//Data Structure Stack LIFO = Last In , First Out.

struct Stack {

	   int   size;
	   
	   char  data[STACK_MAX];
};

typedef struct Stack Stack;

void Stack_Init(Stack *S) {

     S->size = 0;
}

void Stack_Push(Stack *S, char c) {

     if (S->size < STACK_MAX) {
     	
        	S->data[S->size++] = c;

        }   else  {

        	fprintf(stderr, "Error: Stack overflow!\n" );
        }
}

void Stack_Pop(Stack *S) {

     if (S->size == -1)
     {
       	fprintf(stderr, "Stack underflow!\n" );

     } else S->size--; 
}

char Stack_Top(Stack *S) {

    if (S->size == 0)
    {
        fprintf(stderr, "Error: Stack underflow!\n" );

    	return -1;
    }
    return S->data[S->size - 1]; 
}

int _strlen(char *ptr) {

	int c = 0;

	while(*ptr != '\0') {

		   ptr++;

           c++;
    }
           
	return c;
}

int __strlen(char *ptr) {

	char *p = ptr;

	     while(*p != '\0') p++;

	     return p - ptr;  
}

char * reverse(char *ptr) {

      char temp[STACK_MAX];

      printf("\n");

      int count = __strlen(ptr);

      Stack S;

      Stack_Init(&S);

      for (int i = 0; i < count; ++i)
      {
      	Stack_Push(&S, *(ptr + i));
      }

      for (int j = 0; j < count; ++j)
      {
       	   temp[j] = Stack_Top(&S);

       	   Stack_Pop(&S);
      }

      ptr = temp;

      return ptr;
}

int main(int argc, char const *argv[])
{
	char *ptr = "hermann hesse";

      int count = __strlen(ptr);

      for (int i = 0; i < count; ++i)
      {
      	   printf("%c ", *(ptr+i));
      }

	      ptr = reverse(ptr);

      for (int i = 0; i < count; ++i)
      {
      	   printf("%c ", *(ptr+i));
      }
	return 0;
}