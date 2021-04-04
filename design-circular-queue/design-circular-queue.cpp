class MyCircularQueue {
public:
    vector<int> arr;
    int front, rear;
    int s,curr;
    MyCircularQueue(int k) {
        front = -1;
        rear = 0;
        curr = 0;
        s = k;
        arr = vector<int>(s);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            arr[rear] = value;
            front = rear;
            rear = (rear+1)%s;
        }
        else{
            arr[rear] = value;
            rear = (rear+1)%s;
        }
        curr++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        int ret = arr[front];
        front = (front+1)%s;
        curr--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1; 
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1; 
        int tmp = rear-1;
        if(tmp<0) tmp+=s;
        return arr[tmp];
    }
    
    bool isEmpty() {
        return curr == 0;
    }
    
    bool isFull() {
        return curr == s;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */