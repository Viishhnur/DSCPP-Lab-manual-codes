#include<iostream>
#include "Node.cpp"
using namespace std;

// head is pointing to top of stack 
class Stack{
    Node* head;
    int capacity;
    int currentsize;
    
    public:
        
        
        Stack(int c){
            capacity = c;
            head = NULL;
        }

        void push(int);
        void pop();
        void display();
        bool isempty();
        bool isFull();
        

};

bool Stack :: isempty(){
    return (head==NULL);
}

bool Stack :: isFull(){
    return (currentsize==capacity);
}

void Stack :: push(int val){

    Node* newnode = new Node(val);
    if(isempty()){
        // Linked list is empty
        head = newnode; 
        currentsize++;

    }

    else if(!isFull()){

        // insert at head
        newnode->next = head;
        head = newnode;
        currentsize++;
        
    }
    else{
        cout << "Stack Overflow\n";
    }
}

void Stack :: pop(){
    if(isempty()){
        cout << "Stack empty nothing to pop\n";
    }
    else{
        Node* Nodetobedeleted = head;
        head = head->next;
        delete Nodetobedeleted;
        
    }
    
}
void Stack :: display(){
    Node* temp = head;
    while(temp){
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << "Bottom of stack\n";
}
int main(){

    Stack s(5);
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();

    return 0;
}
    
    


