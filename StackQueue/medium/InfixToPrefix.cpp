#include <bits/stdc++.h>
using namespace std;

// Reverse the string and swap '(' with ')' and vice versa
string reverseWithBrackets(string s)
{
    int i = 0;
    int n = s.length()-1;

    while (i < n)
    {
        swap(s[i], s[n]);
        i++;
        n--;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    return s;
}

// Return priority of operators
int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Convert infix expression to prefix
string infixToPrefix(string s)
{
    // Step 1: Reverse the string and adjust brackets
    s = reverseWithBrackets(s);

    stack<char> st;
    string prefix = "";

    for (int i = 0; i < s.length(); i++)
    {
        // If operand, add to prefix
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            prefix += s[i];
        }
        // If opening bracket, push to stack
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        // If closing bracket, pop until opening bracket
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }
            st.pop(); // Remove the opening bracket
        }
        // If operator
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Add remaining operators in the stack
    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }

    // Reverse the final prefix expression
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix = "a+b*(c^d-e)";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}
