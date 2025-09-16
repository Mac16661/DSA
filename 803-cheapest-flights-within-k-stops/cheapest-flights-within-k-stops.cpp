class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build graph: u -> (v, w)
        vector<vector<pair<int,int>>> graph(n);
        for(auto &f : flights) {
            int u = f[0], v = f[1], w = f[2];
            graph[u].push_back({v, w});
        }

        // Min-heap: (cost, node, stops)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        // dist[node][stops] = min cost
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if(node == dst) return cost;  // Found cheapest path

            if(stops > k) continue;  // Too many stops

            for(auto &[next, price] : graph[node]) {
                int newCost = cost + price;
                if(newCost < dist[next][stops+1]) {
                    dist[next][stops+1] = newCost;
                    pq.push({newCost, next, stops+1});
                }
            }
        }

        return -1;
    }
};
