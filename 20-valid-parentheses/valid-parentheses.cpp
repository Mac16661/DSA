class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // loop through all the elements
        for(char c:s) {
            // check if it is open or close bracket
            if(c=='(' || c == '{' || c == '[') {
                st.push(c);
            }else { // close bracket
                if(!st.empty()) {
                    char top = st.top();
                    if((top=='(' and c== ')') || (top=='{' and c== '}') || (top=='[' and c== ']')) {
                        st.pop();
                    }else{
                        return false;
                    }
                }else return false;
            }
        }

        return st.empty();
    }
};