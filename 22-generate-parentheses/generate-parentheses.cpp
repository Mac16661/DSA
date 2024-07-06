class Solution {
public:

    void helper(vector<string> &s, string temp, int open, int close, int n) {
        if(close == n) {
            s.push_back(temp);
            return;
        }

        if(open < n) {
            temp+= '(';
            helper(s, temp,  open+1, close, n);
            temp.pop_back();
        }

        if(close < open) {
            temp+= ')';
            helper(s, temp,  open, close+1, n);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> s;
        string temp = "";

        helper(s,temp,0,0,n);

        return s;
        
    }
};