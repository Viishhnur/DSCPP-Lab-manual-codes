// Given a unosorted array , convert it into a maxHeap from it
#include<iostream>
using namespace std;

void maxHeapify(int arr[],int n,int i){

    int curr_idx = i;
    int leftIndex = 2*i + 1 ;
    int rightIndex = 2*i + 2 ;

    if(leftIndex < n &&  arr[leftIndex] > arr[curr_idx]){
        curr_idx = leftIndex;
    }
    if(rightIndex < n && arr[rightIndex] > arr[curr_idx]){
        curr_idx = rightIndex;
    }

    if(curr_idx!=i){
        // curr_index got updated , 
    // now the current index reached to correct place where the element at index i has to move
    // Swap them
        swap(arr[i],arr[curr_idx]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr,n,curr_idx);
    }
    


}

void insert(int arr[],int n,int val){
    // add the element at the end of array
    arr[n] = val ;
    n++;
    // Now move it to correct place using bottom to top approach
    int i = n - 1; 
    while(i>0){
        int parentIndex = (i-1)/2;
        if(arr[parentIndex]<arr[i]){
            swap(arr[i],arr[parentIndex]);
            i = parentIndex;
        }
        else{
            return ;
        }
    }
    
}
void buildMaxHeap(int arr[],int n){
    for(int i=n/2-1 ; i>=0 ; i--){
        maxHeapify(arr,n,i);
    }
}
int main(){

    int arr[20] = {10,1,23,50,7,-4};
    buildMaxHeap(arr,6);
    for(int i=0;i<6;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
    insert(arr,6,210);
    for(int i=0;i<7;i++){
        cout << arr[i] << " " ;
    }
    

    return 0;
}
