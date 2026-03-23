class Solution {
public:

    long long time_to_eat(vector<int> &v, int hourly) {
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

        // for(int i=1; i<=max_val; i++) {
        //     int time_taken = time_to_eat(piles, i);
        //     if(time_taken <= h) return i;
        // }

        // I guess i am trying to find the lower bound
        while(low <= high) {
            int mid = (low+high)/2;

            long long time_taken = time_to_eat(piles, mid);

            // cout<<low<<" "<<mid<<" "<<high<<" - > "<<time_taken<<endl;

            if(time_taken <= h) {
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};