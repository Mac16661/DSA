class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int sum = 0 ; 
        sort(nums.begin(), nums.end()) ; 
        int i = 0 ; 
        if (n==0)return 0 ; 
        while(k>0 && i<n){
            nums[i] =  -nums[i] ;
            if(i<n-1 && nums[i]>0 && nums[i]> nums[i+1]) i++ ;  // when u convert a -v into +ve
            k-- ; 
        }
        for(auto i : nums) sum+=i ; 
        return sum ; 
    }
};