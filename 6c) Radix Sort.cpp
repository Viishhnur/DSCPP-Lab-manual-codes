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

void countSort(int arr[],int n,int pos){
    // Create a freqency array
    int freq[10] = {0};

    // Now caluclate the frequencies
    for(int i=0;i<n;i++){
        int digit = (arr[i] / pos) % 10 ;
        freq[digit]++;
    }

    // caluclate cumulative frequency
    for(int i=1;i<10;i++){
        freq[i] += freq[i-1];
    }

    // create a answer array
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(arr[i]/pos)%10]] = arr[i];
    }

    // copy elements back into the array
    for(int i=0;i<n;i++){
        arr[i] = ans[i] ;
    }

}
void radixSort(int arr[],int n){

    // step-1 , get the max element 
    int max_ele = getMax(arr,n);
    for(int pos=1;max_ele/pos>0 ; pos*=10){
        countSort(arr,n,pos);
    }


}
int main(){

     int arr[] = {5,4,3,2,3,2};
    int size = sizeof(arr)/sizeof(int);

    radixSort(arr,size);

    for(int n:arr){
        cout << n << " " ;
    }cout << endl;

    return 0;
}
