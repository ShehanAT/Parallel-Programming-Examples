public class Semaphore {
    // Semaphores are used to implement the higher-level monitor construct in Java
    private int value;

    public Semaphore(int initial){
        value = initial;
    }

    synchronized public void up(){
        ++value;
        notifyAll();
    }

    synchronized public void down() throws InterruptedException {
        while(value == 0) wait();
        --value;
    }
}