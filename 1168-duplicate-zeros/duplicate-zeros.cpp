class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // count zeros
        for (int x : arr) {
            if (x == 0) zeros++;
        }

        int i = n - 1;
        int j = n - 1 + zeros;

        // process backwards
        while (i < j) {
            if (arr[i] != 0) {
                if (j < n) arr[j] = arr[i];
            } else {
                if (j < n) arr[j] = 0;
                j--;
                if (j < n) arr[j] = 0;
            }
            i--;
            j--;
        }
    }
};
