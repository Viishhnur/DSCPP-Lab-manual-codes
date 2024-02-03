#include<iostream>
using namespace std;
// Max-Priority Queue using linked list
class Node{
    public:
        int data;
        int priority;
        Node* next;
        Node(int val,int prior): data(val) , priority(prior) , next(nullptr){};
            
};

class PriorityQueue{
    Node* front;
    Node* rear;
    int size;
    public:
        PriorityQueue(){
        size = 0;
        front = rear = NULL;
        }
        void insert(int,int);
        int poll(); // dequeue
        bool isempty();
        int getSize(){
            return size;
        }


};

bool PriorityQueue :: isempty(){
    return (!front || !rear);
}

void PriorityQueue :: insert(int val , int priority){
    size++;
    Node* newnode = new Node(val,priority);
    // Insert at beginning if queue is empty or element has highest priority than front ka element
    if(!front){
        newnode->next = front;
        front = rear = newnode;
    }
    else if((priority > front->priority)){
        newnode->next = front;
        front = newnode;
    }
    else if( priority < rear->priority ){
        // Insert at end
        rear->next = newnode;
        rear = newnode;
    }
    else{
        // Find suitable place to insert
        Node* temp = front; 
        while (temp->next && (temp->next->priority > priority)) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;

        

    }
}
int PriorityQueue :: poll(){
    if(!isempty()){
        int first = front->data;
        front = front->next;
        size--;
        return first;

    }
    return -1;
}


void display(PriorityQueue pq){
    while(!pq.isempty()){
        cout << pq.poll() << " " ;
    }
    cout << endl ;
}

int main(){

    PriorityQueue pq;
    for(int i=1;i<=5;i++){
        int data,prior;
        cout << "Enter data and priority : ";
        cin >> data >> prior;
        pq.insert(data,prior);
    }
    display(pq);
    cout <<"\nFront element is : " <<pq.poll() << endl;
    display(pq);
    cout <<"Queue size is : "<< pq.getSize() << endl;

    return 0;
}
