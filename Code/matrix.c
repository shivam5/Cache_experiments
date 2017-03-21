#include <stdio.h>

#ifndef SIZE 
   #define SIZE 200 
 #endif
int main(){
	FILE *a;
	a= fopen("200.trace","w+");
	int M[SIZE][SIZE];
	int N[SIZE][SIZE];
	int C[SIZE][SIZE];
	int i=0,j=0,k=0;
	for(i =0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			int sum=0;
           for(k=0; k < SIZE; k++) {
               sum += M[i][k] * N[k][j];
               fprintf(a,"0 %p\n", &M[i][k]);
               fprintf(a, "0 %p\n", &N[k][j]);
           }
           C[i][j] = sum;
           fprintf(a,"1 %p\n", &C[i][j]);
		}
	}
	fclose(a);
}
