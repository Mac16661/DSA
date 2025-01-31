#include<bits/stdc++.h>
using namespace std;

// TODO: It is not min stack in true scence because we are not keeping track of the minimum in the stack itself but using an external variable. We can Implement our own stack calls and use this kind of approach. Or use pair data structure to implement st <val, min_val_till_now>

void push(stack<int> &st, int val, int &min){
    if(val < min) {
        min = val;
    }

    st.push(val);
}

int main() {
    stack<int> st;
    int min = INT_MAX;

    push(st, 1, min);
    push(st, 2, min);
    push(st, 3, min);

    cout<<"Min stack -> "<<min<<endl;

    push(st, 0, min);
    push(st, 5, min);

    cout<<"Min stack -> "<<min<<endl;
    
    return 0;
}