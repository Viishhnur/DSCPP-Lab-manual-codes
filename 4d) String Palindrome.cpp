// WAP to check whether a string is a palindrome using stack 
#include<iostream>
#include<stack>
using namespace std;

bool isPalindrome(string s){
    stack<char>st;
    for(int i=0;s[i];i++){
        st.push(s[i]);
    }
    // Now check traversing through the stack
    int i=0;
    while(!st.empty()){
        if(st.top()!=s[i]){
            return false;
        }
        st.pop();
        i++;
    }
    return true;
}
int main(){

    string s = "malayalam";
    if(isPalindrome(s)){
        cout << s <<" is Palindrome\n";
    }else{
        cout << s <<" is not a Palindrome\n";
    }

    return 0;
}
