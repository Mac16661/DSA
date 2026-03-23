class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 0;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto it : graph[front]) {
                // self loop check
                if (front == it) continue;

                if (visited[it] == -1) {
                    visited[it] = 1 - visited[front]; // opposite color
                    q.push(it); 
                }
                else if (visited[it] == visited[front]) {
                    return false; // same color on adjacent nodes
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for (auto &d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        vector<int> visited(n+1, -1);

        for (int i = 1; i <= n; i++) {  // loop should go till n
            if (visited[i] == -1) {
                if (!bfs(i, graph, visited)) return false;
            }
        }
        return true;
    }
};
