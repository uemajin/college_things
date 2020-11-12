#include <stdio.h>
#include <stdlib.h>


int fib (int n)
{ 
   if (n < 2 ) 
	   return n;

	int x,y;
	
	x =  fib(n-1);
	y =  fib(n-2);
	return x+y;
      
}

int main(int argc, char** argv) {
	printf("%d\n", fib(atoi(argv[1])));
}