#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string postfix) {
    stack<string> st;

    for (auto it : postfix) {
        // If the character is an operand, push it as a string onto the stack
        if ((it >= 'A' && it <= 'Z') || 
            (it >= 'a' && it <= 'z') || 
            (it >= '0' && it <= '9')) {
            st.push(string(1, it)); // Convert char to string
        } else { // Operator encountered
            // Pop the top two elements from the stack
            string second = st.top(); // Second operand
            st.pop();

            string first = st.top(); // First operand
            st.pop();

            // Form the prefix expression: operator + operand1 + operand2
            string result = it + first + second;
            st.push(result);
        }
    }

    // The top of the stack will be the resultant prefix expression
    return st.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}
