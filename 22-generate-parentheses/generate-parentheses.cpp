class Solution {
public:
    vector<string> arr;
    void helper(string s, int i, int open, int close, int n) {
        if(close == n) {
            arr.push_back(s);
            return;
        }

        if(open < n) {
            s[i] = '(';
            helper(s, i+1, open+1, close, n);
        }

        if(close < open) {
            s[i] = ')';
            helper(s, i+1, open, close+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        string s(n*2, ' ');
        helper(s, 0, 0, 0, n);
        return arr;
    }
};