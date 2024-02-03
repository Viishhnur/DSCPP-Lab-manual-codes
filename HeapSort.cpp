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


void heapSort(int arr[],int size){
    
    int n = size;
    // Build a max heap from the array
    for(int i=(n/2-1);i>=0;i--){
        maxHeapify(arr,n,i);
    }
    while(n>1){
        // Swap first and last element
        swap(arr[0],arr[n-1]);
        // now decrement the size of arr
        n--;
        // Now move the root node(first element to its correct place by heapifying it)
        maxHeapify(arr,n,0);
    }
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " " ;
    }cout << endl;
}

int main(){

    
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    heapSort(arr, N);
 
    cout << "Sorted array is \n";
    print(arr, N);
    
    

    return 0;
}

