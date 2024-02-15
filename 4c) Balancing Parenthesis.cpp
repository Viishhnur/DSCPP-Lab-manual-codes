/*
Check whether a given bracket sequence is balanced or not
*/
#include<iostream>
#include<stack>
using namespace std;

bool isOpeningBrakcet(char chr){
    if(chr=='(' || chr == '{' || chr == '['){
        return true;
    }
    return false;
}
bool isSameType(char chr, char bracket) {
    if (chr == ']' && bracket == '[') {
        return true;
    } else if (chr == '}' && bracket == '{') {
        return true;
    } else if (chr == ')' && bracket == '(') {
        return true;
    } else {
        return false;
    }
}

bool isBalanced(string s){
    stack<char> st;   
    for(int i=0;s[i];i++){
        if(isOpeningBrakcet(s[i])){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && isSameType(s[i],st.top())){

                st.pop();


            }
            else{
                return false;
            }
            
        }
    }

    return (st.empty());
}
int main(){

    string s = "[[(})]]";

    if(isBalanced(s)){
        cout << "Balanced \n";
    }
    else{
        cout << "Not balanced\n";
    }


    return 0;
}
