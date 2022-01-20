#include <mpi.h>
#define N 10000 // N is a constant of value 10_000


int main (int argc, char *argv[])
{
    int A[N], B[N]; // actually B need only have N/P locations. Could malloc
    int i, rank, answer, P = 10, totalZero = 0;
    int chunksize = (int) ceil( ((double)N) / P); // N/P is the chucksize allocated to each of the ten slaves 

    MPI_Status status;
    MPI_Init (&argc, &argv); // start MPI 
    MPI_Comm_rank (MPI_COMM_WORLD, &rank); // indicate current processer number
    MPI_Comm_size( MPI_COMM_WORLD, &P); // indicate total number of processors
    MPI_Scatter(A, chunksize, MPI_INT, B, chunksize, 0, MPI_COMM_WORLD); // Send data as chucks
    
    totalZero = 0;

    for (i = 0; i < chunksize && rank * chunksize + i < N; i++) {
        totalZero += (B[i] == 0);
    }

    // MPI root process gathers data from all processes while applying reductions over it)
    MPI_Reduce(&totalZero, &answer, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Now we have the answer
    printf (“Number of zeros is %d\n”, answer);
    MPI_Finalize(); // finish MPI 
} 

/*
Repeat the above program but using OpenMP sharing the work across 10 threads 
*/
#define N 10000
#define P 10 

int main(int argc, char *argv[]){
    int A[N], d;
    int i, tid, totalZero = 0;
    // A is initiazed with values 
    #pragma omp parallel num_threads(10)
    {
        #pragma omp for (dynamic, 1) reduction (+: totalZero)
        for(i = 0; i < N; i++){
            totalZero += (A[i] == 0);
        }
    }

    // Now we have the answer 
    printf("Number of zeros is %d\n", totalZero);
}