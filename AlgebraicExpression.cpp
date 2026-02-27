#include <stack>
#include <string>
#include <iostream>
#include <iomanip>

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double applyOp(double a, double b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

std::string infix2postfix(std::string s){
    std::stack<char> st;
    std::string postfix;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            postfix += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                char c = st.top();
                st.pop();
                postfix += c;
            }
            if(!st.empty()){
                char c = st.top();
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        char c = st.top();
        st.pop();
        postfix += c;
    }
    return postfix;
}

double evaluatePostfix(std::string s){
    std::stack<double> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }
        else{
            double val1 = st.top();
            st.pop();
            double val2 = st.top();
            st.pop();
            st.push(applyOp(val2, val1, s[i]));
        }
    }
    return st.top();
}

