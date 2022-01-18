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