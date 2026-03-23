class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0;
        int n = nums.size();

        for(int j=0; j<n; j++) {
            while(i<j && nums[i] != 0) i++;

            // cout<<nums[i] << " "<< nums[j];

            if(nums[j] != 0) {
                // cout<<"Swapped";
                swap(nums[i], nums[j]);
            }
            // cout<<endl;
        }
    }
};