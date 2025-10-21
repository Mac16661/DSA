class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, minSum = A[0], maxSum = A[0], currMax = 0, currMin = 0;
        int n = A.size();

        for(int i=0; i<n; i++) {
            currMax = max(currMax + A[i], A[i]);
            currMin = min(currMin + A[i], A[i]);

            total += A[i];

            minSum = min(minSum, currMin);
            maxSum = max(maxSum, currMax);
        }

        return (maxSum > 0) ? max(total - minSum, maxSum) : maxSum;
        
    }
};