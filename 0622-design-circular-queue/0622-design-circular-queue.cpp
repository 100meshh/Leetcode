// class Queue{
//     int *arr;
//     int front, rear;
//     int size;
//     public:
//     Queue(int n)
//     {
//         arr=new int[n];
//         front=-1;
//         rear=-1;
//         size=n;
//     }
// };
class MyCircularQueue {
    int *arr;
    int front, rear;
    int size;
public:

    MyCircularQueue(int k) {
        arr=new int[k];
        front=-1;
        rear=-1;
        size=k;  
    }
    bool isEmpty() {
        return rear==-1;
    }
    
    bool isFull() {
        return (rear+1)%size==front;
    }
    
    //push
    bool enQueue(int value) {
        if(isEmpty())
        {
            front=rear=0;
            arr[0]=value;
            return true;
        }
        else if(isFull()){
            return false;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=value;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if (front == rear) 
        {
            front = rear = -1;
        }
        else 
        {
            front=(front+1)%size;
        }
            return true;
    }
    
    int Front() {
       if(isEmpty()){
       return -1;
       }
       return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
        return -1;
        }
        return arr[rear];
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