// Linked list implementation of Queue
#include<iostream>
#include "Node.cpp"
using namespace std;

class Queue{

    int size;

    public:
        Node* front;
        Node* rear;
        Queue(){
            front = rear = NULL;
            size = 0 ;
        }

        void enqueue(int);
        void dequeue();
        int getFront(); // get the element which was added first
        bool isempty();
        int getSize();

};

bool Queue :: isempty(){
    return (front==NULL || rear == NULL);
}

int Queue :: getSize(){
    return size;
}

void Queue :: enqueue(int val){
    size++;
    // Adding at the end of the linked list
    Node* newnode = new Node(val);
    if(isempty()){
        front = rear = newnode;
    }
    else{
        // Insert at end using rear pointer 
        rear->next = newnode;
        rear = newnode;
    }
}

void Queue :: dequeue(){
    if(!isempty()){
        // remove from beginning
        // Node* nodetobedelted = front;
        front = front->next;
        // free(nodetobedelted);
        size--;
    }
    else{
        cout << "Queue is empty , nothing to dequeue\n";
        front = rear = NULL;
        size = 0;
    }


}

int Queue :: getFront(){
    return (!isempty())? front->data : -1 ;
}

void display(Queue q){
    Queue tempQueue = q;  // Create a temporary queue to avoid modifying the original
    while(!tempQueue.isempty()){
        cout << tempQueue.getFront() << " ";
        tempQueue.dequeue();
    }
    cout << endl;
}


int main(){
    Queue q;
    for(int i=1;i<=5;i++){
        q.enqueue(i);
    }
    display(q);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    display(q);
    q.enqueue(12);
    display(q);
    cout  << endl;

    return 0;
}
