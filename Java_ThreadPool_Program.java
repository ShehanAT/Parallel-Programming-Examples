import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.Random;

public class ThreadPoolExample {
    /* 
    This program creates 5 tasks and submits them to the executor queue. The executor uses three threads to execute all tasks
    */
    public static void main(String args[]){
        int[] large_int_arr = new int[1_000_000];
        Random random = new Random();
        int randomNumberGen = random.nextInt(100 + 100) - 100;

        for(int i = 0; i < large_int_arr.length(); i++){
            large_int_arr[i] = randomNumberGen;
            randomNumberGen = random.nextInt(100 + 100) - 100;
        }

        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(3);
        int negativeNumCounter = 0;
        for(int i = 1; i <= 5; i++){
            Task task = new Task("Task " + i);
            System.out.println("Created: " + task.getName());

            for(int i = 0; i < large_int_arr.length(); i++){
                task.setArrayNumber(large_int_arr[i]);
                if(task.call()){
                    negativeNumCounter++;
                }
            }
            
            executor.execute(task);
        }

        executor.shutdown();
    }
}

public class Task implements Callable<Boolean> {
    private String name;
    private int arrayNumber;

    public Task(String name){
        this.name = name;
    }

    public void setArrayNumber(arrayNumber){
        this.arrayNumber = arrayNumber;
    }

    public String getName(){
        return name;
    }

    public void run(){
        if(arrayNumber )
    }

    // return true if arrayNumber is a negative even number
    @Override
    public Boolean call(){
        (this.arrayNumber < 0 && this.arrayNumber % 2 == 0) ? return true : return false;
  }
}

