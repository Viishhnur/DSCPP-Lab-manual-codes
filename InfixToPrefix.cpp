#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}
bool isOperand(char ch){
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) ? true : false;
}
string infixToPostfix(string s){
    string res;
    stack<char> st;

    for(int i=0;s[i];i++){
        if(isOperand(s[i])){
            res += s[i];
        }
        else if(s[i] == '('){
            // Just push into stack 
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            // Pop out until u find (
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop() ; // Pop ( 
            }
        }

        else{
            // Operator found check precedence and push into stack
            while(!st.empty() && (precedence(s[i]) <= precedence(st.top()))){
                res += s[i];
                st.pop();
            }
            // Now operator has correct place to insert 
            st.push(s[i]);
            
        }
    }

    while(!st.empty()){
        res += st.top() ;
        st.pop();
    }

    return res;
}

string infixToPrefix(string s){
    // First reverse the string 
    reverse(s.begin(),s.end());
    // Convert ) to ( and ( to ) , vice versa 
    for(int i=0;s[i];i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(' ;
        }
    }
    // Call postfix wallah algorithm
    string res = infixToPostfix(s);
    return res;

}
int main(){

    string s = "(a+b/c)*(a/k-l)";
	
	cout << "Posfix is : " << infixToPostfix(s) << endl;
    cout << "Prefix is : " << infixToPrefix(s) << endl;

	return 0;
}
