#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr) {
    stack<int> st;                 // Stack to keep track of elements
    vector<int> ns(arr.size(), -1); // Initialize result with -1 for all positions

    for (int i = 0 ; i < arr.size(); i++) { // Traverse from right to left
        int element = arr[i];
        
        // Remove elements from the stack that are greater than or equal to current
        while (!st.empty() && st.top() >= element) {
            st.pop();
        }

        // If the stack isn't empty, the top is the next smaller element
        if (!st.empty()) {
            ns[i] = st.top();
        }

        // Push the current element to the stack
        st.push(element);
    }

    return ns;
}



int main() {
    vector<int> arr = {3,2,1};
    vector<int> ans = nextSmallerElement(arr);

    for(auto it: ans) {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}