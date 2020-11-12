#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib (int n)
{ 
   if (n < 2 ) 
	   return n;

	int x,y;
#pragma omp task shared(x) if (n>30)
	x =  fib(n-1);
	
#pragma omp task shared(y) if (n>30)
	y =  fib(n-2);
	
	#pragma omp taskwait
	return x+y;
      
}

int main(int argc, char** argv) {
#pragma omp parallel 
#pragma omp single
	printf("%d\n", fib(atoi(argv[1])));
}