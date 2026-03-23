class Solution {
public:
    int minMoves(vector<int>& nums) {
        // We are calculating how many move req to make all the arr element to the given min element(think in opposite direction)

        int n=*min_element(nums.begin(),nums.end());
        int a=0;
        for(int num:nums){
            a+=(num-n);
        }
        return a;
    }
};