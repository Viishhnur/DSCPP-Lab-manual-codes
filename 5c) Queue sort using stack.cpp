// Check if we can sort a Queue using a stack or not 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

bool checkSorted(queue<int> qu , int n){

    stack<int>st;

    int expected = 1;
    while(!qu.empty()){
        int front_ele = qu.front();
        qu.pop();

        if(front_ele == expected){
            expected++;
        }
        else{
            
            if(!st.empty() && front_ele > st.top()){
                return false;
            }
            else{
                st.push(front_ele);
            }
        }

        while(!st.empty() && st.top() == expected){
            st.pop();
            expected++;
        }
    }

    // if the final expected element value is equal
    // to initial Queue size and the stack is empty.
    return (expected - 1 == n && st.empty());
    

}
int main(){

    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
 
    int n = q.size();
 
    if(checkSorted(q,n)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
