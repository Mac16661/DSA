#include <bits/stdc++.h>
using namespace std;

/*
 * algorithm:
 * step 1: Iteratively check if current element is operand
 * step 2: if yes check whether operator's in top of the stack have higher priotiy if yes than pop it till priority mathers or lower. And also check if current element is closing bracket if yes than pop all the elements till current opeaning breckate
 * step 3: append the popped operand with the operators & return
 */

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' or c == '/')
        return 2;
    else if (c == '+' or c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string Postfix = "";

    for (auto it : infix)
    {
        // when it is not a number
        if ((it >= 'A' && it <= 'Z') || (it >= 'a' && it <= 'z') || (it >= '0' && it <= '9'))
        {
            Postfix = Postfix + it;
        //    cout<<"1"<<it<<endl;
        }
        else if (it == '(')
        { // if opening bracket
            st.push('(');
        }
        else if (it == ')')
        { // if closing bracket
            while (!st.empty() && st.top() != '(')
            {
                Postfix = Postfix + st.top();
                // cout<<it<<endl;
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(it) <= priority(st.top()))
            {
                Postfix = Postfix + st.top();
                // cout<<it<<endl;
                st.pop();
            }
            st.push(it); // insert the current element into the stack
        }
    }
    // insert the remaining operators into the stack
    while (!st.empty())
    {
        Postfix = Postfix + st.top();
        // cout<<st.top()<<endl;
        st.pop();
    }

    return Postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)";
    cout<<infixToPostfix(infix)<<endl;
    return 0;
}