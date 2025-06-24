class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;

        while(i < s.size()) {
            char c = s[i];

            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
                i++;
            }else{
                if(!st.empty()) {
                    
                    if(st.top() == '(' && c == ')') st.pop();
                    else if(st.top() == '[' && c == ']') st.pop();
                    else if(st.top() == '{' && c == '}') st.pop();
                    else  st.push(c);
                }else{
                    st.push(c);
                }
                i++;
            }
        }

        return st.empty();
    }

};