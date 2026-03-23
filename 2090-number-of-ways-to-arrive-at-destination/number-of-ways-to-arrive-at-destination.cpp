class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> graph(n);
        for (auto &it : roads) {
            int u = it[0], v = it[1], w = it[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [adjNode, adjWeight] : graph[node]) {
                if (d + adjWeight < dist[adjNode]) {
                    dist[adjNode] = d + adjWeight;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if (d + adjWeight == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
