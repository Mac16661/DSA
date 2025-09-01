class Solution {
public:
    int dfsCycle(int node, vector<int>& edges, vector<int>& visited, vector<int>& timeVisited, int step) {
        visited[node] = 1;
        timeVisited[node] = step;

        int next = edges[node];
        int cycleLen = -1;

        if (next != -1) {
            if (visited[next] == 0) {
                cycleLen = dfsCycle(next, edges, visited, timeVisited, step + 1);
            } else if (visited[next] == 1) {
                // Found a cycle -> length = current step + 1 - timeVisited[next]
                cycleLen = step + 1 - timeVisited[next];
            }
        }

        visited[node] = 2; 
        return cycleLen;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> timeVisited(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans = max(ans, dfsCycle(i, edges, visited, timeVisited, 0));
            }
        }
        return ans;
    }
};
