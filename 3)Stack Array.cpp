#include<iostream>
using namespace std;

class Stack{

    private:
        int capacity;
        int* arr; // This is pointer to the first element of stack
        int topindex;

    public:
        // Parametrised constructor
        Stack(int maxsize){
            capacity = maxsize;
            // dynamically create a array of size = capacity
            arr = new int[capacity];
            topindex = -1; 
        }    
        bool isFull();
        bool isempty();
        void push(int);
        void pop();
        void display();
        int getTop();
        int size();



};

bool Stack :: isempty(){
    return (topindex==-1);
}

bool Stack :: isFull(){
    return (topindex==capacity-1);
}

void Stack :: push(int val){
    if(!isFull()){
        topindex+=1;
        arr[topindex] = val;

    }

    else{
        cout << "\nStack overflow\n";
    }
    

}

void Stack :: pop(){
    if(!isempty()){
        topindex-=1;
    }
    else{
        cout << "Stack empty or underflow\n";
    }
}

int Stack :: getTop(){
    if(!isempty()){
        return arr[topindex];
    }
    else{
        cout << "Stack is empty\n";
        return -1;
    }
}

int Stack :: size(){
    return topindex+1;
}
void Stack :: display(){
    if(!isempty()){
        for(int i=topindex;i>=0;i--){
        cout << arr[i] << endl;
    }

    }

    else{
        cout << "Stack is empty\n";

    }
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
    cout << "After popping top three elements: \n";
    s.display();
    cout << "Current size of stack is : " << s.size()<<endl;
    cout << "Top element is : " << s.getTop()<<endl;

    return 0;
}
