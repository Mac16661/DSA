class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1); // 1-based indexing
        for(auto& it: times) {
            int u = it[0], v = it[1], w = it[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k}); // {distance, node}

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]) continue; // skip outdated entry (set like behaviour)

            for(auto& it: graph[node]) {
                int adjNode = it.first;      
                int adjWeight = it.second;   
                if(dis + adjWeight < dist[adjNode]) {
                    dist[adjNode] = dis + adjWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};
