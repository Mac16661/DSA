class Solution {
public:
    int findKth(int k, vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, cnt = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    while (i < n1 && j < n2) {
        int val;
        if (nums1[i] <= nums2[j])
            val = nums1[i++];
        else
            val = nums2[j++];

        if (cnt == k)
            return val;
        cnt++;
    }

    while (i < n1) {
        if (cnt == k)
            return nums1[i];
        cnt++, i++;
    }

    while (j < n2) {
        if (cnt == k)
            return nums2[j];
        cnt++, j++;
    }

    return -1; // unreachable
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if (total % 2 == 0) {
        return (findKth(total / 2, nums1, nums2) + findKth(total / 2 - 1, nums1, nums2)) / 2.0;
    } else {
        return findKth(total / 2, nums1, nums2);
    }
}

};