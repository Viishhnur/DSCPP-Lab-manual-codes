#include<iostream>
using namespace std;
#define MAX 20

class Heap{

    int arr[MAX];
    int size;
    public:
        Heap(){
            size = 0;
        }

        void insert(int);
        void deleteRoot();
        int extract_max();
        void print();
        void heapify(int arr[],int,int);
        int getSize();

};

void Heap :: heapify(int arr[],int n,int i){
    int curridx = i;
    int leftIndex = 2*i + 1 ;
    int rightIndex = 2*i + 2 ;

    if(leftIndex<n && arr[leftIndex]>arr[curridx]){
        curridx = leftIndex;
    }
    if(rightIndex<n && arr[rightIndex]>arr[curridx]){
        curridx = rightIndex;
    }

    if(curridx!=i){
        // Node has reached its correct place
        // swap them
        swap(arr[curridx],arr[i]);
        heapify(arr,n,curridx);
    }
}
void Heap :: insert(int val){
    // Insert at the last
    int index = size;
    size += 1;
    arr[index] = val;
    // Now move the node to its correct position using bottom to top approach

    while(index>=0){
        int parentIdx = (index-1)/2;
        if(arr[index]>arr[parentIdx]){
            swap(arr[index],arr[parentIdx]);
            index = parentIdx;
        }
        else{
            return;
        }

    }
}

void Heap :: deleteRoot(){
    if(size==0) {
        cout << "Nothing to delete";
        return ;
    }
    cout << "Delete called \n";
    // get the last element
    int lastele = arr[size-1];
    // replace the first elemnt with last element
    arr[0] = lastele;
    // decrement the size 
    size--;
    // Now move the root node to its correct position using heapify method
    heapify(arr,size,0);
    // Note while deleting the root node the relative positions of its children may change

}
int Heap :: getSize(){
    return size;
}
int Heap :: extract_max(){
    if(size!=0) return arr[0];
    return -1;
}
void Heap :: print(){
    for(int i=0;i<size;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main(){

    Heap heap;
    heap.insert(54);
    heap.insert(53);
    heap.insert(55);
    heap.insert(52);
    heap.insert(70);
    heap.print();
    cout << "Heap size : " << heap.getSize()<<endl;
    heap.deleteRoot();
    heap.print();
    heap.deleteRoot();
    heap.print();
    cout << "Heap size : " << heap.getSize()<<endl;
    heap.deleteRoot();
    heap.print();
    cout << "Max element in heap is : " << heap.extract_max() << endl;
    heap.deleteRoot();
    heap.deleteRoot();
    heap.deleteRoot();
    cout << endl;

    

    return 0;
}
