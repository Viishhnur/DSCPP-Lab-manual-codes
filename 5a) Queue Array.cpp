#include<iostream>
using namespace std;
class Queue{

    private:
        int size=0;
    public:
        int capacity;
        int* arr;
        int frontindex; // used to remove element from start
        int rearindex;  // used to add element at the end

        Queue(int maxsize){
            capacity = maxsize;
            arr = new int[capacity];
            frontindex = -1;
            rearindex = -1;
        }

        void enqueue(int);
        void dequeue();
        int front(); // get the element which was added first
        bool isempty();
        bool isFull();
        int getSize();
    

};

int Queue :: getSize(){
    return size;
}
bool Queue :: isempty(){
    return (getSize()==0);
}

bool Queue :: isFull(){
    return (rearindex+1 == capacity);
}

void Queue :: enqueue(int val){
    
    // adding at the end
    if(isempty()){
        frontindex = rearindex = 0 ;
        arr[rearindex] = val;
        size++;
    }
        
    else if(!isFull()){
        rearindex += 1 ;
        arr[rearindex] = val;
        size++;
    }
    else{
        cout << "Queue is full , cannot add more elements\n";
    }

}

void Queue :: dequeue(){
    // removing element from the front
    if(frontindex<=rearindex){
        frontindex += 1 ; 
        size--;
    }
    else{
        cout << "\nQueue is empty cannot remove any element\n";
        frontindex=-1;
        rearindex=-1;
        size = 0;
    }
}

int Queue :: front(){
    if(!isempty()){
        return arr[frontindex];
    }
    return -1;
}

void display(Queue q){
    
    
    if(q.isempty()){
        cout << "Queue is empty nothing to display\n";
    }
    else{
        while(!q.isempty()){
            cout << q.front() << " " ;
            q.dequeue();
        }
    }

    cout << endl ;
}


int main(){

    Queue q(5);
    for(int i=1;i<=5;i++){
        q.enqueue(i);
    }
    display(q);
    for(int i=1;i<=5;i++){
        q.dequeue();
    }
    display(q);

    for(int i=10;i<=50;i+=10){
        q.enqueue(i);
    }
    display(q);

    q.dequeue();
    display(q);
    cout  << endl;

    return 0;
}
