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
}
finally {
locks[i].unlock();
}
}
public int empty(int i) {
locks[i].lock();
try {
int res = box[i];
box[i] = 0;
return res;
}
finally {
locks[i].unlock();
}
}
}
• No finally: -2