#include <stdio.h>

#ifndef SIZE 
   #define SIZE 500 
#define TILE 50
 #endif

int main(){
	FILE *a;
	a= fopen("op500.trace","w+");
	int M[SIZE][SIZE];
	int N[SIZE][SIZE];
	int C[SIZE][SIZE];
	int sum=0;
	int i=0,j=0,k=0,x=0,y=0,z=0;
	for (i=0; i<SIZE; i+=TILE ){
        for (j=0; j<SIZE; j+=TILE ){
            for (k=0; k<SIZE; k+=TILE ){
                for (y=i; y<i+TILE; y++ ){
                    for (x=j; x<j+TILE; x++ ){
                        for (z=k; z<k+TILE; z++ ){
                           sum = sum+M[y][z]*N[z][x];
                            fprintf(a,"0 %p\n", &M[y][z]);
               				fprintf(a, "0 %p\n", &N[z][x]);

                        }
                        C[y][x] = sum;
                        fprintf(a,"1 %p\n", &C[y][x]);
                    }
                }
            }
        }
	}
	fclose(a);
}
