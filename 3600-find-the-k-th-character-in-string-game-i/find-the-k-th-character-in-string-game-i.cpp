class Solution {
public:
    char ans;
    void helper(int k, string s) {
        int n = s.size();

        if(n >= k) {
            // for(auto c:s) cout<<c;
            // cout<<endl<<s[k];
            ans = s[k-1];
            return;
        }

        for(int i=0; i<n; i++) {
            s.push_back(s[i] + 1);
        }

        helper(k, s);
    }

    char kthCharacter(int k) {
        helper(k, "a");
        return ans;
    }
};