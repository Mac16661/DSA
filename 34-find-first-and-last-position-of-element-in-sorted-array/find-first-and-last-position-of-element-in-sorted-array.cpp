class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
            if (nums[mid] == target) first = mid;
        }
        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) low = mid + 1;
            else high = mid - 1;
            if (nums[mid] == target) last = mid;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int first = findFirst(nums, target);
        if (first == -1) return {-1, -1};
        int last = findLast(nums, target);
        return {first, last};
    }
};
