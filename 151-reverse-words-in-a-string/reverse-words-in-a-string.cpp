class Solution {
public:
    
    string reverseWords(string s) {
        string temp="";
        string ans="";
        stack<string> st;

        for( int i=0; i<s.length();i++) {
            if(s[i] != ' '){
                temp+= s[i];
            }else{
                if(temp.length() > 0) {
                    st.push(temp);
                    temp="";
                }
            }
        }

        if (!temp.empty()) {
            st.push(temp);
        }


        while(!st.empty()) {
            ans+= st.top();
            st.pop();

            if(!st.empty()){
                ans+=" ";
            }
        }

        return ans;
    }
};