#define ll long long
class Solution {
public:
    // optimal
    long long subArrayRanges(vector<int>& nums) {
        ll sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int sml = nums[i];
            int lrg = nums[i];
            for(int j=i; j<n; j++){
                if(nums[j] > lrg){
                    lrg = nums[j];
                }else if(nums[j] < sml) {
                    sml = nums[j];
                }

                sum += lrg - sml;
            }
            
        }

        
        return sum;
    }
};
