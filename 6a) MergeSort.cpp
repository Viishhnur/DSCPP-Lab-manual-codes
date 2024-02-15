#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements from temp back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low==high) return;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    // Call merge to merge sorted arrays
    merge(arr,low,mid,high);
}

int main(){
    int arr[] = {10, -5, 23, -17, 0, 8, -12, 15, -3, 7};
    int size = sizeof(arr) / sizeof(int);
    mergeSort(arr,0,size-1);
    cout << "Sorted array : ";
    for(int n:arr){
        cout << n << " " ;
    }
    cout << endl ;
    return 0;
}
