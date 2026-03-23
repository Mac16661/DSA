class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> special(nums.size(), 0);
        vector<bool> ans;

        // Using prefix techinique -> range sum
        for(int i = 1;i < nums.size();i++){
            if(nums[i] % 2 != nums[i - 1] % 2){
                special[i] = special[i - 1] + 1;
            }else{
                special[i] = 0;
            }
        }

        for(auto i : queries){
            if(i[1] - i[0] == special[i[1]] - special[i[0]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};