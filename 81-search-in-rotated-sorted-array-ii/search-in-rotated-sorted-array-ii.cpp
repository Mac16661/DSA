class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) return true;

        // If duplicates are found, adjust low and high
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        } else if (nums[low] <= nums[mid]) {
            // If left side is sorted
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // If right side is sorted
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}
};