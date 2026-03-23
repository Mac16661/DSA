class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        if(n<=2) {
            string s = to_string(nums[0]) + to_string(nums[1]);
            return stoi(s);
        }

        int i=0, j=n-1;
        long long sum = 0;

        while(i<j) {
            string s = to_string(nums[i]) + to_string(nums[j]);
            sum += stoi(s);
            i++;
            j--;
        }

        if(n%2==1) sum+=nums[i];

        return sum;
    }
};