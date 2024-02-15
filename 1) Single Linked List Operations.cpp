#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }

};

class Linkedlist{
    
    int size;
    public:
        Node* head;
        Linkedlist(){
            head = NULL;
            size = 0;
        }

        bool isempty();
        int getSize();
        void insertEnd(int);
        void insertHead(int);
        void insertAtPos(int,int);
        void deleteHead();
        void deleteEnd();
        void deleteAtPos(int);
        void display();
        void recursiveSearch(Node*,int);
        Node* mergeSort(Node*);
        Node* merge(Node*,Node*);
        Node* findMiddle(Node*);


};

bool Linkedlist :: isempty(){
    return (head==NULL);
}

int Linkedlist :: getSize(){
    return size;
}

void Linkedlist :: insertHead(int val){
    size++;
    Node* newnode = new Node(val);
    if(isempty()){
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;

}

void Linkedlist :: insertEnd(int val){
    size++;
    Node* newnode = new Node(val);
    if(isempty()){
        head = newnode;
        return;
    }
    Node* temp = head;
    // Traverse till end of LL to insert at last
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}

void Linkedlist :: insertAtPos(int val,int pos){
    // Insert at index
    size++;
    Node* newnode = new Node(val);
    int curr_pos = 0;
    Node* temp = head;
    while(temp && curr_pos!=pos-1){
        temp = temp->next;
        curr_pos++;
    }
    newnode->next = temp->next;
    temp->next = newnode;


}

void Linkedlist :: deleteHead(){
    if(!isempty()){
        head = head->next;
        size--;
    }
    else{
        cout << "\nLinked list is empty nothing to delete\n";
    }
}

void Linkedlist :: deleteEnd(){
    if(!isempty()){
        size--;
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }
    else{
        cout << "\nLinked list is empty nothing to delete\n";
    }
}

void Linkedlist :: deleteAtPos(int pos){
    if(pos==0){
        deleteHead();
        return;
    }
    else if(pos==getSize()-1){
        deleteEnd();
        return;
    }
    else{
        size--;
        int curr_pos = 0;
        Node* temp = head;
        while(temp && curr_pos!=pos-1){
            temp = temp->next;
            curr_pos++;
        }
        temp->next = temp->next->next;

    }
}

void Linkedlist :: recursiveSearch(Node* curr,int val){
    if(!curr){
        cout << val << " Not found \n";
        return;
    }
    if(curr && curr->data == val){
        cout << val << " Found in Linked list\n";
        return;
    }

    recursiveSearch(curr->next,val);

}

Node* Linkedlist :: merge(Node* lefthead,Node* righthead){

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(lefthead && righthead){
        if(lefthead->data < righthead->data){
            temp->next = lefthead;
            temp = lefthead;
            lefthead = lefthead->next;
        }else{
            temp->next = righthead;
            temp = righthead;
            righthead = righthead->next;
        }
    }

    temp->next = (lefthead)? lefthead : righthead;
    return dummyNode->next;

}
Node* Linkedlist :: findMiddle(Node* head){

    Node* slow = head;
    Node* fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;

}
Node* Linkedlist :: mergeSort(Node* head){
    if(head == NULL || head->next==NULL){
        return head;
    }

    Node* lefthead = head;
    Node* middle = findMiddle(head);
    Node* righthead = middle->next;
    middle->next = NULL;


    lefthead = mergeSort(lefthead);
    righthead = mergeSort(righthead);

    return merge(lefthead,righthead);

}
void Linkedlist :: display(){
    if(isempty()) cout << "\nLinkedList is empty nothing to display\n";
    else{
        Node* temp = head;
        while(temp){
            cout << temp->data << "->";
            temp = temp->next;
        }cout << "NULL  \n";
    }
}


int main(){

    Linkedlist ll;
    for(int i=1;i<=8;i++){
        ll.insertEnd(i);
    }
    ll.display();
    ll.insertAtPos(-121,5);
    ll.display();

    cout << "Current size of linked list is : " << ll.getSize() << endl;
    ll.deleteEnd();
    ll.deleteHead();
    ll.display();
    cout << "Current size of linked list is : " << ll.getSize() << endl;
    ll.deleteAtPos(3);
    ll.display();
    cout << "Current size of linked list is : " << ll.getSize() << endl;
    ll.recursiveSearch(ll.head,125);

    ll.head = ll.mergeSort(ll.head);
    ll.display();

    return 0;
}
