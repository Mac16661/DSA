class NumArray {
public:
    vector<int> prefix;
    vector<int> nums;
    int n;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        for (int i = index; i < n; i++) {
            prefix[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return (left > 0) ? prefix[right] - prefix[left - 1] : prefix[right];
    }
};
