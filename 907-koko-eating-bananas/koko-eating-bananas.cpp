class Solution {
public:

    long long totalTime(vector<int> &v, int hourly) {
        long long totalH = 0;
        int n = v.size();
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(auto i: piles) {
            maxi = max(maxi, i);
        }

        int low = 1;
        int high = maxi;
        int ans = high;

        while(low<=high) {
            int mid = (low+high)/2;
            long long totalH = totalTime(piles, mid);

            if(totalH <= h){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};