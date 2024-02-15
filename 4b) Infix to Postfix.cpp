#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return -1;
}

bool isOperand(char ch){
    return ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) ? true : false;
}

string InfixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i = 0; s[i]; i++){
        if(isOperand(s[i])){
            res += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop(); // Pop the '('
        }
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;
}

int main(){

    string s = "(a+b/c)*(a/k-l)";
	
	cout << "Posfix is : " << InfixToPostfix(s) << endl;
	return 0;
}
