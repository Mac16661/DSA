class Solution {
public:
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