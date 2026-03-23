class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);

        for (auto& e : prerequisites) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            indeg[v]++;
        }

        vector<vector<bool>> reach(n, vector<bool>(n, false));

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v : graph[u]) {
                reach[u][v] = true;
                for (int i = 0; i < n; ++i)
                    if (reach[i][u]) reach[i][v] = true;

                if (--indeg[v] == 0) q.push(v);
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& qy : queries) {
            ans.push_back(reach[qy[0]][qy[1]]);
        }
        return ans;
    }
};
