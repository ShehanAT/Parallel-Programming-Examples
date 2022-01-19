/*
Write a sequential C program to reads two integer N x N arrays and perform matrix multiplication of A*B and save results in new matrix C, 
assume both matrices A and B are diagonal matrices, (i.e. all elements off the diagonal are zeros), this should be taken in consideration to minimize the loops and coding. 
N is a defined constant set to 1000. Assume matrices A and B have already been initialised
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));   // Initialization, should only be called once.
    int randomNumber = rand()%((20+1)); 

    int rowCountOne, columnCountOne, rowCountTwo, columnCountTwo, i, j, k, sum = 0;
    int firstMatrix[10][10], secondMatrix[10][10];
    int resultMatrix[5];

    // create and populate two 2d arrays
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(i == j){
                firstMatrix[i][j] = randomNumber;
                randomNumber = rand()%((20+1));

                secondMatrix[i][j] = randomNumber;
                randomNumber = rand()%((20+1));
            }else{
                firstMatrix[i][j] = 0;
                secondMatrix[i][j] = 0;
            }
          
        }
    }

    int resultMatrixInc = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(i == j){
                resultMatrix[resultMatrixInc] = (firstMatrix[i][j] * secondMatrix[i][j]);
                resultMatrixInc++;
            }
            
        }
    }




    scanf("%d", &firstMatrix[i][j]);
}

/*
Modify the code using OpenMP directives to parallelize the code using P threads, where P is also a defined constant and N is a multiple of P.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main()
{
    srand(time(NULL));   // Initialization, should only be called once.
    int randomNumber = rand()%((20+1)); 

    int rowCountOne, columnCountOne, rowCountTwo, columnCountTwo, i, j, k, sum = 0;
    int firstMatrix[10][10], secondMatrix[10][10];
    int resultMatrix[5];

    #pragma omp parallel {
        // create and populate two 2d arrays
        #pragma omp for 
            for (i = 0; i < 10; i++){
                for (j = 0; j < 10; j++){
                    if(i == j){
                        firstMatrix[i][j] = randomNumber;
                        randomNumber = rand()%((20+1));

                        secondMatrix[i][j] = randomNumber;
                        randomNumber = rand()%((20+1));
                    }else{
                        firstMatrix[i][j] = 0;
                        secondMatrix[i][j] = 0;
                    }
                
                }
            }

        int resultMatrixInc = 0;
        #pragma omp for 
            for (i = 0; i < 10; i++){
                for (j = 0; j < 10; j++){
                    if(i == j){
                        resultMatrix[resultMatrixInc] = (firstMatrix[i][j] * secondMatrix[i][j]);
                        resultMatrixInc++;
                    }
                }
            }
    }
}

/* 
Finally re-write the code to be an MPI program with P processes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main()
{
    MPI_Init(&argc, &argv);

    srand(time(NULL));   // Initialization, should only be called once.
    int randomNumber = rand()%((20+1)); 

    int rowCountOne, columnCountOne, rowCountTwo, columnCountTwo, i, j, k, sum = 0;
    int firstMatrix[10][10], secondMatrix[10][10];
    int resultMatrix[5];

   
    // create and populate two 2d arrays
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(i == j){
                firstMatrix[i][j] = randomNumber;
                randomNumber = rand()%((20+1));

                secondMatrix[i][j] = randomNumber;
                randomNumber = rand()%((20+1));
            }else{
                firstMatrix[i][j] = 0;
                secondMatrix[i][j] = 0;
            }
        
        }
    }

    int resultMatrixInc = 0;

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(i == j){
                resultMatrix[resultMatrixInc] = (firstMatrix[i][j] * secondMatrix[i][j]);
                resultMatrixInc++;
            }
        }
    }

    return MPI_Finalize();
}