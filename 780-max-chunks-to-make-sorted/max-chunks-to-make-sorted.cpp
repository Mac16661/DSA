class Solution {
public:
    vector<int> NSE(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size(), -1);

        for(int i=arr.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() >= arr[i]) st.pop();

            if(!st.empty()) ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }

    int maxChunksToSorted(vector<int>& arr) {
         stack<int> st;
    for (int a : arr) {
        int maxVal = a;
        while (!st.empty() && st.top() > a) {
            maxVal = max(maxVal, st.top());
            st.pop();
        }
        st.push(maxVal);
    }
    return st.size();
    }
};