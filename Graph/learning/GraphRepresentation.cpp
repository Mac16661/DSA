#include<bits/stdc++.h>
using namespace std;

// Adjacency Matrix
void Am() {
    int n,m;

    cin>>n>>m;

    int adj[n+1][n+1];

    for(int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// Adjacency Lists
void Al() {
    int n,m;

    cin>> n>> m;

    vector<int> adj[n+1]; // vector<vector<int>> of size n+1
    for(int i=0; i<m; i++) {
        int u,v;
        cin>> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// Directed graph
void directedAl() {
    int n,m;

    cin>> n>>m;

    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        cin>> u >> v;

        adj[u].push_back(v);
    }
}

int main() {
    // Am();
    // Al();
    directedAl();
    return 0;
}