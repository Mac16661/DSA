class Solution {
public:

    bool helper(int ind, string &ans, vector<string>& nums) {
        if(ind == nums[0].size()) {
            for(auto i: nums) {
                if(i==ans) return false;
            }    

            // nums.push_back(ans);
            return true;  
        }

        ans+="0";
        if(helper(ind+1, ans, nums)) {
            return true;
        }
        ans.pop_back();

        ans+="1";
        if(helper(ind+1, ans, nums)) {
            return true;
        }
        ans.pop_back();

        return false;

    }

    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        helper(0, ans, nums);

        return ans;
    }
};