class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                cnt++;

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < n; j++) {
                        if (isConnected[node][j] == 1 && !visited[j]) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return cnt;
    }
};