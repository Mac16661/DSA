class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       // monotonic stack approach
       int cnt = 0;
       stack<int> st;

       for(int i:arr) {
            int maxV = i;
            while(!st.empty() && st.top() > i) {
                maxV = max(st.top(), maxV);
                st.pop();
            }
            
            st.push(maxV);
       } 
       return st.size();
    }
};