class Solution {
public:
    bool palindrome(string s, int ind, int i) {
            while(ind <= i){
                if(s[ind] != s[i]) return false;
                ind++; i--;
            }
            return true;
    }

    void helper(string& s, vector<string>& temp, vector<vector<string>>& ans, int ind){
        if(ind == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            // check palindrome
            if(palindrome(s, ind, i)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                helper(s, temp, ans, i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        helper(s, temp, ans, 0);

        return ans;
    }
};