class Solution {
public:
    string removeStars(string s) {
        string ans = "";

        int i=0;
        while(i<s.size()) {
            if(i!=0 && s[i] == '*') {
                ans.pop_back();
            }else{
                if(s[i] != '*') ans.push_back(s[i]);
            }
            // cout<<ans<<endl;
            i++;
        }

        return ans;
    }

    // string removeStars(string s) {
    //     stack<char> st;

    //     int i=0;
    //     while(i<s.size()) {
    //         if(i!=0 && s[i] == '*') {
    //             st.pop();
    //         }else{
    //             if(s[i] != '*') st.push(s[i]);
    //         }
    //         // cout<<ans<<endl;
    //         i++;
    //     }

    //     string ans;

    //     while(!st.empty()) {
    //         ans.push_back(st.top());
    //         st.pop();
    //     }

    //     reverse(ans.begin(), ans.end());

    //     return ans;
    // }
};