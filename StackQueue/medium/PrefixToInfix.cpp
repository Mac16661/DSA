#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string prefix) {
    stack<string> st;

    // Iterate over the prefix string in reverse order
    for (int i = prefix.length() - 1; i >= 0; i--) {
        // If the character is an operand, push it as a string onto the stack
        if ((prefix[i] >= 'A' && prefix[i] <= 'Z') || 
            (prefix[i] >= 'a' && prefix[i] <= 'z') || 
            (prefix[i] >= '0' && prefix[i] <= '9')) {
            st.push(string(1, prefix[i])); // Convert char to string
        } 
        else { // Operator encountered
            // Pop the top two elements from the stack
            string first = st.top();  // First operand
            st.pop();

            string second = st.top();  // Second operand
            st.pop();

            // Create the infix expression with brackets and push it back
            string result = "(" + first + prefix[i] + second + ")";
            st.push(result);
        }
    }

    // The top of the stack will be the resultant infix expression
    return st.top();
}

int main() {
    string prefix = "*+PQ-MN";
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}
