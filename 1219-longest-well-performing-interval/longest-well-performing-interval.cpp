class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len = hours.size();
        vector<int> prefixSum(len+1, 0);
        for (int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + (hours[i-1] > 8 ? 1 : -1);
        }
        stack<int> smdStack;
        for (int i = 0; i <= len; ++i) {
            if (smdStack.empty() || prefixSum[smdStack.top()] > prefixSum[i]) {
				// Trick, store index than value.
                smdStack.push(i);
            }
        }
        int res = 0;
        for (int j = len; j >= 0; --j) {
		    // For generalized problem:
		    // while (!smdStack.empty() && prefixSum[smdStack.top()]+K <= prefixSum[j]) {
            
			// For this problem:
			while (!smdStack.empty() && prefixSum[smdStack.top()] < prefixSum[j]) {
                res = max(res, j - smdStack.top());
                smdStack.pop();
            }
        }
        return res;
    }
};