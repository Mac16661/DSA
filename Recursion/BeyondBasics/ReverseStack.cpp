#include<bits/stdc++.h>
using namespace std;

// void ReverseStack(stack<int> &st) {
//     if(st.empty()) return;

//     int temp = st.top();
//     st.pop();

//     ReverseStack(st);

//     stack<int> tempStack;

//     while(!st.empty()) {
//         tempStack.push(st.top());
//         st.pop();
//     }

//     st.push(temp);

//     while(!tempStack.empty()) {
//         st.push(tempStack.top());
//         tempStack.pop();
//     }   
// }

void insertAtBottom(stack<int> &st, int ele) {
    // if(st.empty()) {
    //     st.push(ele);
    //     return;
    // }

    // int top = st.top();
    // st.pop();
    // insertAtBottom(st, ele);

    // st.push(top);

    stack<int> tempStack;

    while(!st.empty()) {
        tempStack.push(st.top());
        st.pop();
    }

    st.push(ele);

    while(!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }  
}

void reverse(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int ele = st.top();
    st.pop();

    reverse(st);
    insertAtBottom(st,ele);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()) {
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverse(s);

    while(!s.empty()) {
        cout<< s.top()<<" ";
        s.pop();
    }
    return 0;
}