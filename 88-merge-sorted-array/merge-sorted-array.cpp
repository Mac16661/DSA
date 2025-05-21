class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int j=0;
        for(int i=n-1; i>=0; i--) {
            nums1[m+j] = nums2[i];
            j++;
        }

        for(int i=n-1; i>=0; i--) {
            cout<<nums1[i]<<" ";
        }

        sort(nums1.begin(), nums1.end());
    }
};