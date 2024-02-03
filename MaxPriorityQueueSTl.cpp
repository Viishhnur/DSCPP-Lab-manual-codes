#include<iostream>
#include<queue>
using namespace std;

void display(priority_queue<int> pq){
    while(!pq.empty()){
        cout << pq.top() << " " ;
        pq.pop();
    }
    cout << endl ;
}
int main(){

    // Create a priority queue object 
    priority_queue<int> pq; // By default it is a maxHeap, so we will get a sorted array of numbers in descending order
    for(int i=1;i<=5;i++){
        pq.push(i);
    }
    display(pq);
    cout << "Size : " << pq.size() << endl;


    return 0;
}
