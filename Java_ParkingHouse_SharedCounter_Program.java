import java.util.concurrent.locks.*;

class ParkingHouseCounter{

    private int nrOfCars = 0;
    private static final int MAX = 107;
    
    private Lock lock = new ReentrantLock();
    private Condition full = lock.newCondition();
public void inc(){
	lock.lock();
	try{
	    while(nrOfCars == MAX) full.await();
	    nrOfCars++;
	}catch(InterruptedException e){
	    System.out.println(e.getMessage());
	}finally{lock.unlock();}
    }

    public void dec(){
	lock.lock();
	try{
	    nrOfCars--;
	    full.signal();
	}finally{lock.unlock();}
    }

    public static void main(String args[]){
        ParkingHouseCounter parkingHouseCounter = new ParkingHouseCounter();
        
        ThreadPool threadPool = new ThreadPool(5, 10);
        threadPool.execute(() -> {
            synchronized (this) {
                while (CAPACITY == mItems.size()) {
                        try 
                        { 
                            wait(); 
                        } 
                        catch (InterruptedException e) 
                        {
                            e.printStackTrace();
                        }
                }
                parkingHouseCounter.inc();
                notifyAll();
            }
        });
    }

    }
}

class CarParkControl {
    protected int spaces;
    protected int capacity;

    CarParkControl(int n){
        capacity = spaces = n;
    }
    
    // mutual exclusion is implemented by the 'synchronized' methods 
    synchronized void arrive() throws InterruptedException { 
        while(spaces == 0) wait();
        --spaces;
        notifyAll();
    }

    synchronized void depart() throws InterruptedException { 
        while(spaces == capacity) wait();
        ++spaces;
        notifyAll();
    }


}

class CarPark {
    public static void main(String args[]){
        
    }
}

class Arrivals implements Runnable {
    CarParkControl carpark;

    Arrivals(CarParkControl c) {
        carpark = c;
    }    

    public void run(){
        try{
            while(true){
                ThreadPanel.rotate(330);
                carpark.arrive();
                ThreadPanel.rotate(30);
            }
        }catch(InterruptedException e){

        }
    }
}

class Departures implements Runnable {

    public void run(){

    }
}

