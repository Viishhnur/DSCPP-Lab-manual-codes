#include<iostream>
using namespace std;

// Time:- O(NlogN) , Space:- O(1)
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int leftptr = low;
    int rightptr = high;
    while(leftptr<rightptr){
        
        while(arr[leftptr] <= pivot && leftptr<=high){
            leftptr++;
        }

        while(arr[rightptr] > pivot && rightptr>=low){
            rightptr--;
        }

        if(leftptr<rightptr){
            swap(arr[leftptr],arr[rightptr]);
        }
    }

    swap(arr[low],arr[rightptr]);

    return rightptr;

}

void quickSort(int arr[],int low,int high){

    if(low<high){
        // Take a pivot , put it in its right place
        // Now move it into right place by using partition technique
        int pivotIdx = partition(arr,low,high);
        quickSort(arr,low,pivotIdx-1);
        quickSort(arr,pivotIdx+1,high);
    }


}
int main(){

    int arr[] = {4,6,2,5,7,9,1,3};
    quickSort(arr,0,7);
    for(int num:arr){
        cout << num << " " ;
    }cout << endl;


    return 0;
}
