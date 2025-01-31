#include<bits/stdc++.h>
using namespace std;

vector<int> nextGraterElement(vector<int> arr){
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; --i) {
        int element = arr[i];
        
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        int nextGreater = -1;
        if(!st.empty()){
            nextGreater = st.top();
        }

        st.push(element);
        arr[i] = nextGreater;
        
    }
    return arr;

}

vector<int> nextGraterElement2(vector<int> arr){
    stack<int> st;
    vector<int> ng(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; --i) {
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        st.push(arr[i]);
    }

    // Or use striver way to use i= 2N-1 & if i<N st.top()
    for (int i = arr.size() - 1; i >= 0; --i) {
        int element = arr[i];
        
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        int nextGreater = -1;
        if(!st.empty()){
            nextGreater = st.top();
        }

        st.push(element);
        ng[i] = nextGreater;
        
    }
    return ng;

}

int main() {
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> ans = nextGraterElement2(arr);

    for(auto it: ans) {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}