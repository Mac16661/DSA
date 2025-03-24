class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto i : s) {
            if(i=='(' || i == '[' || i == '{') {
                st.push(i);
            }else {
                if(!st.empty()) {
                    char c = st.top();
                    if(c=='(' && i==')') st.pop();
                    else if(c=='[' && i==']') st.pop();
                    else if(c=='{' && i =='}') st.pop();
                    else st.push(i);
                }else {
                    st.push(i);
                }
                
            }
        }

        if(st.size() > 0) return false;
        return true;
    }
};