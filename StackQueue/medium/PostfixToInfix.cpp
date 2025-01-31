#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string postfix) {
    stack<string> st;

    for(auto it: postfix){
        // if operand push it 
        if((it>='A' && it<='Z') || (it>='a' && it<='z') || (it>='0' && it<='9')) {
            st.push(string(1, it)); // appending char to empty string will make it string
        }else{ //else pop last 2 element add operator in bw & cover it with brackets and push it to the stack
            // Operator, pop two operands, apply operator, and push back the result
            string second = st.top();  // second operand
            st.pop();

            string first = st.top();  // first operand
            st.pop();

            // Add brackets around the expression and push back to the stack
            string result = "(" + first + it + second + ")";
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    cout<<postfixToInfix(postfix)<<endl;
    return 0;
}