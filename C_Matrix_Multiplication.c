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
    int B[10][10], C[10][10];
    int A[5];

    // create and populate two 2d arrays
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(i == j){
                B[i][j] = randomNumber;
                randomNumber = rand()%((20+1));

                C[i][j] = randomNumber;
                randomNumber = rand()%((20+1));
            }else{
                B[i][j] = 0;
                C[i][j] = 0;
            }
          
        }
    }

    int resultMatrixInc = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if(i == j){
                A[resultMatrixInc] = (B[i][j] * C[i][j]);
                resultMatrixInc++;
            }
            
        }
    }
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
    int B[10][10], C[10][10];
    int A[10][10];

    #pragma omp parallel {
        // create and populate two 2d arrays
        #pragma omp for 
            for (i = 0; i < 10; i++){
                for (j = 0; j < 10; j++){
                    if(i == j){
                        B[i][j] = randomNumber;
                        randomNumber = rand()%((20+1));

                        C[i][j] = randomNumber;
                        randomNumber = rand()%((20+1));
                    }else{
                        B[i][j] = 0;
                        C[i][j] = 0;
                    }
                
                }
            }

        int resultMatrixInc = 0;
        #pragma omp for 
            for (i = 0; i < 10; i++){
                for (j = 0; j < 10; j++){
                    if(i == j){
                        B[i][j] = (B[i][j] * C[i][j]);
                        resultMatrixInc++;
                    }
                }
            }
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main()
{
    int N = 10;
    int A[N][N];
    int resultArr[N]; // This is the one dimensional array where the results of the row averaging calculation are saved
    int currentRowValue = 0;

    #pragma omp parallel {
        // create and populate two 2d arrays
        #pragma omp for 
            for (i = 0; i < N; i++){
                for (j = 0; j < N; j++){
                    currentRowValue += A[i][j]; // add up all the elements in the current row 
                }
                currentRowValue = currentRowValue / N; // Get the average of the current row 
                resultArr[i] = currentRowValue; // assign current row average to 1d array 
                currentRowValue = 0; // reset counter variable for use in next row 
            }

    }
}


// Question 2b 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <assert.h>

int main(int argc, char** argv) {

    int N = 10;
    int A[N][N];
    int resultArr[N]; // This is the one dimensional array where the results of the row averaging calculation are saved
    int currentRowValue = 0;


    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            currentRowValue += A[i][j]; // add up all the elements in the current row 
        }
        currentRowValue = currentRowValue / N; // Get the average of the current row 
        resultArr[i] = currentRowValue; // assign current row average to 1d array 
        currentRowValue = 0; // reset counter variable for use in next row 
    }

  MPI_Finalize();
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


// Question 3c

import java.util.concurrent.Semaphore;

public class ClassroomControl {
    // Anly allow one person to sing at a time
    static Semaphore semaphore = new Semaphore(100);
    
    public synchronized static void EnterClass(){
        try {
            // Acquire a permit to proceed, if limit is exceeded this will throw an error
            semaphore.acquire();
            System.out.println("DoReMiFaSoLaTiDo!");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public synchronized void LeaveClass(){
        try {
            // Release permit so that students in queue
            semaphore.release();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
public class Main {
    private ClassroomControl classControl; 

    public static void main(String args[]){
        // generate 30 students every 5 minutes = every 300 seconds = generate 1 student every 10 seconds
        // And From your main() method or any other method
        Timer timer = new Timer();
        timer.schedule(new Student(), 0, 10000); // 10000ms = 10 seconds 
       
        
    }
}

class Student extends TimerTask {
        public void run() {
            // do a task 
        }
    }
}

// Question 4a
public class MyList{
    private int[] list = new int[100];
    Object locks[];

    public MyList(){
        for(int j = 0; j < 100; j++){
            list[j] = (int)(Math.random() * 100);
            locks[j] = new Object();
        } 
    }

    public void set(int x, int ind){ 
        synchronized(locks[x]){
            list[x] = ind;
        }
  
    }

    public void inc(int x, int ind){ 
        synchronized(locks[x]){
            list[x] = list[x] + ind;
        }
    }



}


// Question 4b

class Q4{

    private boolean f[] = new boolean[20];

    public Q4(){ for(int j = 0; j < 20; j++) f[j] = true }

    public synchronized void negate(int a, int b){
        for(int j = a; j < b; j++) f[j] = !f[j];
    }

    public synchronized void swap(int a, int b){
        boolean temp = f[a];

        f[a] = f[b];
        f[b] = temp;
    }
}

// Question 5a
public class Buffer {

    int value; // this is the single integer value 
    private Lock lock = new ReentrantLock(); // this Lock is used to prevent deadlocks and race conditions
    private Condition ready = lock.newCondition(); // use a Condition to know whether or not writer and read threads are allowed to do their operations

    public int read(){
        synchronized(lock){
            while(!ready()){ // waiting for writer thread to complete in order to read value 
                lock.wait();
            }
        }
        return value;
    }

    public void write(int k){
        synchronized(lock){
            if(value != null){
                // if the buffer contains a value the writer thread waits for the current value of the buffer to be read by another thread 
                lock.wait();
            }
            value = k; // here, the writer thread is okay to write
            lock.notifyAll(); // after writer thread is done writing, we call notifyAll() to signal read thread to execute
        }
    }
}