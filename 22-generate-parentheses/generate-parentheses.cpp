class Solution {
public:
    void helper(vector<string>& ans, int open, int close, int n, string s, int i) {
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }

        if(open < n){
            s[i] = '(';
            helper(ans, open+1, close, n, s, i+1);
        }

        if(open > close) {
            s[i] = ')';
            helper(ans, open, close+1, n , s, i+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s(n*2, ' ');
        helper(ans, 0, 0, n, s, 0);
        return ans;
    }
};