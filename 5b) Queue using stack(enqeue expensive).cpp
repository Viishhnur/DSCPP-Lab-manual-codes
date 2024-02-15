#include<iostream>
#include<stack>
// Enqueue is expensive
using namespace std;
// Just change the property of stack 
class Queue{
    int size;
    stack<int> st1,st2;
    public:
        Queue(){
            size = 0;
        }
        void enqueue(int);
        int dequeue();
        bool isempty();
        int getSize();


};

int Queue :: getSize(){
    return size;
}
bool Queue :: isempty(){
    return (st1.empty());
}
void Queue :: enqueue(int val){
    size++;
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    // Now insert the element at the bottom of stack
    st1.push(val);

    // Retranfer the contents into st1 from st2
    while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
    }
    
}

int Queue :: dequeue(){
    // Simply pop out the elements
    if(!st1.empty()){
        size--;
        int first_element = st1.top();
        st1.pop();
        return first_element;
    }
    return -1;
    
}


void display(Queue q){
    Queue tempqueue = q ;
    while(!tempqueue.isempty()){
        cout << tempqueue.dequeue() << " ";
        
    }
    cout << endl;
}
int main(){

    Queue qu;
    for(int i=1;i<=5;i++){
        qu.enqueue(i);
    }
    display(qu);
    cout << qu.dequeue() << " got dequeued" << endl;
    display(qu);
    cout << "Size of Queue is : " << qu.getSize() << endl;

    

    return 0;
}
