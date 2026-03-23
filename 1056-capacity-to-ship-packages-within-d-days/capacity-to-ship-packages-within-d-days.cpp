class Solution {
public:
    int dayReq(vector<int>& weights, int capacity) {
         int cnt = 1;  // at least one day needed
        int sum = 0;
        for (int w : weights) {
            if (sum + w > capacity) { // exceed capacity → start new day
                cnt++;
                sum = 0;
            }
            sum += w;
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
         int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int numberOfDays = dayReq(weights, mid);
            if (numberOfDays <= days) {
                //eliminate right half
                high = mid - 1;
            }
            else {
                //eliminate left half
                low = mid + 1;
            }
        }
        return low;
    }
};