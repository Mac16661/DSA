// TODO: Priority queue implementation of dijkstra algo

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {distance, node}

vector<int> dijkstra(int V, vector<vector<pii>>& adj, int src) {

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first; // {dist, node}
        int node = pq.top().second;
        pq.pop();

        if (currDist > dist[node]) continue;

        for (auto edge: adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if(dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5; // number of vertices
    vector<vector<pii>> adj(V);

    // Graph:
    // 0 --(4)-- 1
    // 0 --(1)-- 2
    // 2 --(2)-- 1
    // 1 --(1)-- 3
    // 2 --(5)-- 3
    // 3 --(3)-- 4

    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[2].push_back({1, 2});
    adj[1].push_back({2, 2});

    adj[1].push_back({3, 1});
    adj[3].push_back({1, 1});

    adj[2].push_back({3, 5});
    adj[3].push_back({2, 5});

    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});

    int source = 0;

    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " = ";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
