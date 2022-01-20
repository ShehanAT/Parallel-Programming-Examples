class DeliveryLocked {
	private int[] box;
	private Lock[] locks;
	public DeliveryLocked(int n) {
		box = new int[n];
		for (int i = 0; i < n; i++) {
			box[i] = 0;
			locks[i] = new ReentrantLock();
		}
	}
	public void deliver(int parcels, int i) {
		locks[i].lock();
		try {
			box[i] = box[i] + parcels;
		} finally {
			locks[i].unlock();
		}
	}
	public int empty(int i) {
		locks[i].lock();
		try {
			int res = box[i];
			box[i] = 0;
			return res;
		} finally {
			locks[i].unlock();
		}
	}

    public void transfer(Lock a, Lock b, int parcels){
        locks[a].lock();
        locks[b].lock();

        box[a] = box[b];

        locks[a].unlock();
        locks[b].unlock();
    }
}•

/*
Give a thread safe lock-free version of Delivery.
*/

import java.util.concurrent.atomic.*;
class DeliveryLockFree {
	private AtomicIntegerArray box;
	public DeliveryLockFree(int n) {
		box = new AtomicIntegerArray(n);
		for (int i = 0; i < n; i++) {
			box.set(i, 0);
		}
	}
	public void deliver(int parcels, int i) {
		int oldBox;
		int newBox;
		do {
			oldBox = box.get(i);
			newBox = oldBox + parcels;
		}
        /*
            compareAndSet() is an inbuilt method that atomically sets the element at the position to the given updated value 
            params:
            i: the index where the operation is to be made 
            oldBox: The expected value to check if it is equal to current value 
            newBox: The value to be updated
        */ 
		while (!box.compareAndSet(i, oldBox, newBox));
	}
	public int empty(int i) {
		int oldBox;
		do {
			oldBox = box.get(i);
		}
		while (!box.compareAndSet(i, oldBox, 0));
		return oldBox;
	}
}