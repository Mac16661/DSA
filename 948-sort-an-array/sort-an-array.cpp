class Solution {
public:
    // Create a new temp arr inserting element form the left & right in sorted order
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        // merge two sorted halves
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {   // no need for special == handling
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // copy remaining left half
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // copy remaining right half
        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        // copy temp back to nums[left..right]
        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    // divide arr into equal parts until u cant
    void mergeSort(vector<int>& nums, int left, int right) {

        if(left >= right) return;

        int mid = (left+right)/2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        // lets implement merge sort
        mergeSort(nums, 0 , nums.size()-1);

        return nums;
    }
};