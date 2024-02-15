// WAP to evaluate any postfix expression 
#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
// Time and Space :- O(N)
float calc(float a , char op , float b){
    switch(op){
        case '^' : return pow(a,b);
        case '*' : return a*b;
        case '/' : return a/b ;
        case '+' : return a+b;
        default : return a-b;
    }
    
}
float evaluatePostfix(string s){
    stack<float>st;
    for(int i=0;s[i];i++){
        if(isdigit(s[i])){
            float num = s[i] - '0' ;
            st.push(num);
        }
        else{
            // Operator found pop out last two elements
            if(!st.empty()){
                float last_ele = st.top();
                st.pop();
                if(!st.empty()){
                    float last_second_ele = st.top();
                    st.pop();
                    st.push(calc(last_second_ele,s[i],last_ele));
                }
            }
            
        }
    }

    return (not st.empty())? st.top() : -1; 
}
int main(){

    string s = "92*74+/3-";
    cout << s << " = " << evaluatePostfix(s) << endl;

    return 0;
}
