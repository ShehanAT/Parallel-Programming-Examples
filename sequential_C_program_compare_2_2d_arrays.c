
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

bool compareFirstBiggerThanSecond(int a, int b)
{
	if (a > b)
    {
        return true;
    }
	return false;
}
 
int main(int argc, char **argv)
{
	int a[10][10], b[10][10];
	int n, i;
	
	srand(time(NULL));   // Initialization, should only be called once.

	int randomNumber = rand()%((20+1)); 
	
// 	for(i = 0; i < n; i++)
// 		scanf("%d", &a1[i]);
    for(i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j] = randomNumber;
            randomNumber = rand()%((20+1));  
        }
    }
    
    for(i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            b[i][j] = randomNumber;
            randomNumber = rand()%((20+1)); 
        }
    }

	int aElementsGreaterThanbElementCounter = 0;
	
	for(i = 0; i < 10; i++){
	    for(int j = 0; j < 10; j++){
	        printf("%d ", a[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");
	
	for(i = 0; i < 10; i++){
	    for(int j = 0; j < 10; j++){
	        printf("%d ", b[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");
	
	for(i = 0; i < 10; i++){
	    for(int j = 0; j < 10; j++){
	        if(compareFirstBiggerThanSecond(a[i][j], b[i][j]) == true){
	            aElementsGreaterThanbElementCounter++;
	        }
	    }
	}
	printf("aElementsGreaterThanbElementCounter: %d", aElementsGreaterThanbElementCounter);
    return 0;
}

/*
Modify the code using OpenMP directives to parallelize the code using P threads, 
where P is also a defined constant and N is a multiple of P.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

bool compareFirstBiggerThanSecond(int a, int b)
{
	if (a > b)
    {
        return true;
    }
	return false;
}
 
int main(int argc, char **argv)
{
	MPI_Init(); 

	int a[10][10], b[10][10];
	int n, i;
	
	srand(time(NULL));   // Initialization, should only be called once.

	int randomNumber = rand()%((20+1)); 
	
// 	for(i = 0; i < n; i++)
// 		scanf("%d", &a1[i]);
    for(i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j] = randomNumber;
            randomNumber = rand()%((20+1));  
        }
    }
    
    for(i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            b[i][j] = randomNumber;
            randomNumber = rand()%((20+1)); 
        }
    }

	int aElementsGreaterThanbElementCounter = 0;
	
	for(i = 0; i < 10; i++){
	    for(int j = 0; j < 10; j++){
	        printf("%d ", a[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");
	
	for(i = 0; i < 10; i++){
	    for(int j = 0; j < 10; j++){
	        printf("%d ", b[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");
	
	for(i = 0; i < 10; i++){
	    for(int j = 0; j < 10; j++){
	        if(compareFirstBiggerThanSecond(a[i][j], b[i][j]) == true){
	            aElementsGreaterThanbElementCounter++;
	        }
	    }
	}
	printf("aElementsGreaterThanbElementCounter: %d", aElementsGreaterThanbElementCounter);
    
	MPI_Finalize();

	return 0;

}
