#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp; // dp[remaining][started]

    int dfs(int remaining, bool started) {
        if (remaining == 0)
            return started ? 1 : 0; // valid only if we already used at least one part

        // Memoization check
        if (dp[remaining][started] != -1)
            return dp[remaining][started];

        int best = started ? remaining : 0; // if started, we can choose to stop (no more splits)
        // Try all possible first parts
        for (int i = 1; i < remaining; ++i) {
            int product = i * dfs(remaining - i, true);
            best = max(best, product);
        }

        return dp[remaining][started] = best;
    }

    int integerBreak(int n) {
        dp.assign(n + 1, vector<int>(2, -1));
        return dfs(n, false);
    }
};
