class Searcher extends Thread {
             
        private int f[];
        private int a, b;
        private int x;
        boolean found;
        
        Searcher(int f1[], int a, int b, int x) {
            f = f1; this.a = a; this.b = b; this.x = x;
        }



        public void run() {
           int k = a; found = false;
        	 while (k < b && !found){
        	    if(f[k] == x) found = true;
        	    k++;	
        	} 
        }
        boolean getResult() {
        	return found;
        }        
}

class LinearSearch{
	public static void main(String args[]){
		int list[] = new int[100];
           // get data and value for x
	       Searcher t = new Searcher(list,0,50,x);
		Searcher t1 = new Searcher(list,50,100,x);
		t.start(); t1.start();
		try{
			t.join(); t1.join();
		}
		catch(InterruptedException e){}
		boolean found = t.getResult() || t1.getResult();
		System.out.println("Found = " + found);	
}}

class Found{
	private boolean found = false;
	public void set(){found = true;}
	public boolean found(){return found;}
	public String toString(){return found+"";}
} 

   Searcher(int f1[], int a, int b, int x, Found fd) {
     f = f1; lb = a; ub = b; this.x = x; fnd = fd;
   }
   public void run() {
     int k = lb;
     while (k < ub && !fnd.found()){
        if(f[k] == x) fnd.set();
        k++;
     }
   }

   class SelectionSort extends Thread{
        int dt[];
        int a, b;

        public SelectionSort(int f[], int a, int b){ 
                // f[a..b) to be sorted
            dt = f; this.a = a; this.b = b;
        }

        public void run(){
            for(int i = a; i < b; i++){
                int j = i; int k = i + 1;
                while(k < b){
                    if(dt[j] > dt[k])
                        j = k;
                    else
                        ; //skip
                    k++;
                }
                //swap dt[j] with dt[i]
                int temp = dt[i]; dt[i] = dt[j]; dt[j] = temp;
            }
        }
    }


  class RankerNoDup extends Thread{
        int data[]; int copy[];int i;
        public RankerNoDup(int d[], int c[], int k){
            data = d; copy = c; i = k;
        }
        public void run(){
            int rank = 0;
            for (int j = 0; j < data.length; j++)
            if (data[j] < data[i])  rank++;
            copy[rank] = data[i];
        }
    }

    class Sorting{
        public static void main(String args[]){
                        // 1 million values
            int f[] = new int[1000000];
            int n1 = 500000;
            int n2 = 1000000;
            for(int j = 0; j < f.length; j++) 
                f[j] = (int)(Math.random()*100);
            Thread t = new SelectionSort(f,0,n1);
            Thread t1 = new SelectionSort(f,n1, n2);
            long startTime = System.currentTimeMillis();
            t.start();t1.start();
            try{
                t.join();t1.join();
            }
            catch(InterruptedException e){}
            //merge component parts
            int c[] = new int[f.length];
            int k = 0;int j = 0;int h = n1;
            while(j < n1 && h < n2){
                if(f[j] <= f[h]){
                    c[k] = f[j];
                    j++;
                }
                else{
                    c[k] = f[h];
                    h++;
                }
                k++;
            }
            while(j < n1){ c[k] = f[j];  k++; j++; }
            while(h < n2){c[k] = f[h]; k++; h++;}
            f = c;
            long endTime = System.currentTimeMillis(); 
            long runningTime = endTime-startTime;
            System.out.println(runningTime + " millisecs ("
                        +(runningTime/1000.0) + ")");
            System.out.println();
            System.out.println();

            Thread [] workers = new Thread[data.length];
            //Record start time
            long startTime = System.currentTimeMillis();
            for(int i = 0; i < data.length; i++){
                workers[i] = new RankerNoDup(data,copy,i);
                workers[i].start();
            }

            for (int k = 0; k < workers.length; k++){
                try {
                    workers[k].join();
                }catch (InterruptedException e) {}
            }
           
            //Record end time
            long endTime = System.currentTimeMillis();

        }
  }









   


