class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        n--;
        int index = 0; // 0:*, 1:/, 2:+, 3:-
        while (n > 0) {
            if (index % 4 == 0) {
                int top = st.top(); st.pop();
                st.push(top * n);
            } else if (index % 4 == 1) {
                int top = st.top(); st.pop();
                st.push(top / n);
            } else if (index % 4 == 2) {
                st.push(n);
            } else {
                st.push(-n);
            }
            index++;
            n--;
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};