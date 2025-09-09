class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        set<char> st;

        for(int i=0; i<s.size(); i++) {
            if(st.count(s[i]) != 0) {
                // for(auto c: st) cout<<c;
                // cout<<endl;
                st.clear();
                cnt++;
                st.insert(s[i]);
                continue;
            }

            st.insert(s[i]);
        }

        return cnt+1;
    }
};