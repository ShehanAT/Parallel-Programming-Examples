#include <mpi.h>
#define N 10000
int main (int argc, char *argv[])
{
    int A[N], B[N]; // actually B need only have N/P locations. Could malloc
    int i, rank, answer, P = 10, totalZero = 0;
    int chunksize = (int) ceil( ((double)N) / P);

    MPI_Status status;
    MPI_Init (&argc, &argv); // start MPI 
    MPI_Comm_rank (MPI_COMM_WORLD, &rank); // indicate current processer number
    MPI_Comm_size( MPI_COMM_WORLD, &P); // indicate total number of processors
    MPI_Scatter(A, chunksize, MPI_INT, B, chunksize, 0, MPI_COMM_WORLD); // includes master here

    totalZero = 0;

    for (i = 0; i < chunksize && rank * chunksize + i < N; i++) {
        totalZero += (B[i] == 0);
    }

    MPI_Reduce(&totalZero, &answer, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Now we have the answer
    printf (“Number of zeros is %d\n”, answer);
    MPI_Finalize(); // finish MPI 
} 