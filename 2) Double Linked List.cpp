#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        // Constructor
        Node(int val) : data(val) , prev(NULL) , next(NULL) {} ;

};

class DoubleLinkedList{
    int size;
    Node* head;
    Node* tail;
    public:
        DoubleLinkedList() : head(NULL) , tail(NULL) ,size(0) {} ;


        void insertHead(int);
        void insertTail(int);
        void insertAtIndex(int,int);
        bool isempty();
        void DeleteEnd();
        void DeleteHead();
        void deleteAtIndex(int);
        int len();
        void display();
        void Reverse();
        // void reverseRecursion(Node*,Node*,int);

};
int DoubleLinkedList :: len(){
    return size;
}
void DoubleLinkedList :: insertHead(int val){
    size++;
    Node* newnode = new Node(val);
    if(head==NULL){
        head = tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void DoubleLinkedList :: insertTail(int val){
    size++;
    Node* newnode = new Node(val);
    if(tail==NULL){
        head = tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void DoubleLinkedList :: insertAtIndex(int val,int pos){
    if(pos==0){
        insertHead(val);
        
    }
    else if(pos==len()){
        insertTail(val);
    }
    else{
        size++;
        Node* newnode = new Node(val);
        int currpos = 0 ;
        Node* temp = head;
        while(temp && currpos!=pos-1){
            temp = temp->next;
            currpos++;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;



    }

}
void DoubleLinkedList :: DeleteHead(){
    if(!head || !tail) cout << "Nothing to delete\n";
    else{
        size--;
        head = head->next;
        head->prev = NULL;
    }
}

void DoubleLinkedList :: DeleteEnd(){
    if(!head || !tail) cout << "Nothing to delete\n";
    else{
        size--;
        tail = tail->prev;
        tail->next = NULL;
    }
}

void DoubleLinkedList :: deleteAtIndex(int pos){
    if(pos==0){
        DeleteHead();
    }
    else if(pos==len()-1){
        DeleteEnd();
    }
    else{
        size--;
        int currpos = 0;
        Node* temp = head;
        while(temp && currpos!=pos){
            temp = temp->next;
            currpos++;
        }
        // Now currpos is at pos
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}

void DoubleLinkedList :: Reverse(){
    if(!head || !tail) return ;
    Node* curr = head;
    while(curr!=nullptr){
        Node* next_item_ptr = curr->next;
        curr->next = curr->prev;
        curr->prev = next_item_ptr;
        curr = next_item_ptr;
    }

    // Now swap head and tail
    swap(head,tail);
    return;

}

// void DoubleLinkedList :: reverseRecursion(Node* curr,Node* next_item_ptr,int l){
//     if(l==len()){
//         swap(head,tail);
//         return ;
//     }
//     if(next_item_ptr!=nullptr && curr->next!=nullptr){

//         curr->next = curr->prev;
//         curr->prev = next_item_ptr;
//         next_item_ptr = curr->next; // Save the next pointer before updating it

//         curr = next_item_ptr;
//         reverseRecursion(curr, next_item_ptr,l+1);

//     }

// }

void DoubleLinkedList :: display(){
    if(head && tail){
        Node* temp = head;
        cout << "NULL<-";
        while(temp){
            cout << temp->data << "<->" ;
            temp = temp->next;

        }cout << "NULL\n";
    }
}
int main(){

    DoubleLinkedList dll;
    for(int i=1;i<=5;i++){
        dll.insertTail(i);
    }
    dll.display();

    dll.insertHead(121);
    dll.display();
    
    dll.DeleteEnd();
    dll.DeleteHead();
    dll.display();

    dll.insertAtIndex(500,3);
    dll.display();

    dll.deleteAtIndex(3);
    dll.display();

    dll.Reverse();
    dll.display();

    return 0;
}
