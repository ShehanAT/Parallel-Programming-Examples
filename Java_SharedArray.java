

// Coarse-grained locking 
class CourseGrainedSharedArray {
    int data[];

    public SharedArray(int f[]){
        data = new int[f.length];
        for(int j = 0; j < f.length; j++){
            data[j] = f[j];
        }
    }

    synchronized void assign(int j, int x) { data[j] = x; }
    synchronized void inc(int j, int x) { data[j] = data[j] + x; }
    synchronized int get(int j){ return data[j]; }
}


// Fine-grained locking 
class FineGrainedSharedArray {
    int data[];
    Object locks[];
    
    public SharedArray(int f[]){
        data = new int[f.length];
        locks = new Object[f.length];
        for(int j = 0; j < f.length; j++){
            data[j] = f[j];
            locks[j] = new Object();
        }
    }

    public void assign(int j, int x){
        // logic is contained in a synchronized block in order to prevent race conditions and deadlocks 
        synchronized(locks[j]){
            data[j] = x;
        }
    }

    public void inc(int j, int x){
        synchronized(locks[j]){
            data[j] = data[j] + x;
        }
    }

    public int get(int j){
        synchronized(locks[j]){
            return data[j];
        }
    }
}