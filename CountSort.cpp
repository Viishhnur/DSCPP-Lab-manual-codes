#include<iostream>
using namespace std;

int getMax(int arr[],int n){
    int maxnum = INT16_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxnum){
            maxnum = arr[i];
        }
    }
    return maxnum;
}

void countSort(int arr[],int n){
    // step-1 , get the max element
    int max = getMax(arr,n);

    // step-2 , Create a freq array to store freq of digits
    int freq[max+1] = {0};

    // step-3 , caluclate frequency of each and every element and store in freq array
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    
    // step-4 , Caluclate cumulative frequency(by traversing through freqency array)
    for(int i=1;i<=max;i++){
        freq[i] += freq[i-1];
    }

    // step-5 , Create a answer array
    int ans[n];
    for(int i=n-1;i>=0;i--){
        int pos = --freq[arr[i]];
        ans[pos] = arr[i] ;
    }

    // step-6 , copy back the ans to original array
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}
int main(){

    int arr[] = {5,4,3,2,3,2};
    int size = sizeof(arr)/sizeof(int);

    countSort(arr,size);

    for(int n:arr){
        cout << n << " " ;
    }cout << endl;
    return 0;
}
