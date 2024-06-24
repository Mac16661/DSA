#include<bits/stdc++.h>
using namespace std;

void sortStackM1(stack<int> s) {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();

    // recursive call
    sortStackM1(s);

    stack<int> tempStack;

    // pushing valuse from stack one to temp stack
    while(s.top() > temp && !s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }

    s.push(temp); // inserting elements at its right position

    while(!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

void sortStack(stack<int> &s) {
    // If the stack is empty, return
    if (s.empty())
        return;
     
    // Remove the top element of the stack
    int x = s.top();
    s.pop();
     
    // Sort the remaining elements in the stack using recursion
    sortStack(s);
     
    // Create two auxiliary stacks
    stack<int> tempStack;
     
    // Move all elements that are greater than x from the main stack to the tempStack
    while (!s.empty() && s.top() > x) {
        tempStack.push(s.top());
        s.pop();
    }
     
    // Push x back into the main stack
    s.push(x);
     
    // Move all elements from tempStack back to the main stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> s;

    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    sortStack(s);

    while(!s.empty()) {
        cout<< s.top()<<" ";
        s.pop();
    }
    return 0;
}