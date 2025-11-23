class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // sliding window approach
        int n = nums.size();
        int maxCnt = 0;

        if(n<=2){
            if((n==2) && (nums[0] < nums[1] || nums[0] > nums[1])) return 2;
            else return 1; 
        }

        for(int i=1; i<n; i++) {
            int j=i;
            while(j<n && nums[j-1] < nums[j]) { // increasing order
                j++;
                maxCnt = max(maxCnt, j-i+1);
            }
            int k=i;
            while(k<n && nums[k-1] > nums[k]) { // decreasing order
                k++;
                maxCnt = max(maxCnt, k-i+1);
            }

            i=min(j,k);
        }

        // for(int i=1; i<n; i++) {
        //     int j=i;
        //     while(j<n && nums[j-1] > nums[j]) { // decreasing order
        //         j++;
        //         maxCnt = max(maxCnt, j-i+1);
        //     }
        //     i=j;
        // }

        return max(1,maxCnt);

    }
};