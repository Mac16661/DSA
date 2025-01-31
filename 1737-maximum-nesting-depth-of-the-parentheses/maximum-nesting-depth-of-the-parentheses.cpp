class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxValue = 0;

        for(auto ch : s) {
            if(ch == '(') {
                st.push(ch);
            }else if (ch == ')'){
                if(!st.empty()) st.pop();
            };
            int n = st.size();
            // cout<<n<<endl;
            maxValue = std::max(maxValue,n);
        }
        return maxValue;
    }

    
};