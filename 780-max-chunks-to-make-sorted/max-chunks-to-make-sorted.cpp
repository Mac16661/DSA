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

        for (int x : arr) {
            if (st.empty() || x >= st.top()) {
                st.push(x);
            } else {
                int maxInChunk = st.top();
                st.pop();
                
                while (!st.empty() && st.top() > x) {
                    st.pop();
                }
                st.push(maxInChunk);  
            }
        }

        return st.size();  
    }
};