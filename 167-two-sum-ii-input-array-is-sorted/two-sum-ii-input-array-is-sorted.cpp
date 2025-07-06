class Solution {
public:
    int bs(vector<int>& numbers, int target, int start) {
        int low=start;
        int high = numbers.size()-1;

        while(low <= high) {
            int mid = (low+high) / 2;

            if(numbers[mid] == target) {
                return mid;
            }else if(numbers[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        
        // O(n) time
        for(int i=0; i<numbers.size(); i++) {
            int rem = target - numbers[i];

            // O(logn)
            int found = bs(numbers, rem, i+1);

            if(found != -1) {
                ans[0] = i+1;
                ans[1] = found+1;
            }
        }

        return ans;
    }
};