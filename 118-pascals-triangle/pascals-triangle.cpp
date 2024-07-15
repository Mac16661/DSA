class Solution {
public:
    //Optimal approach
    vector<int> helper(int n) {
        long long ans = 1;
        vector<int> temp;

        temp.push_back(ans);

        for(int i=1; i<n; i++) {
            ans = ans * (n-i);
            ans = ans / i;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1; i<=numRows; i++) {
            ans.push_back(helper(i));
        }

        return ans;
    }
};