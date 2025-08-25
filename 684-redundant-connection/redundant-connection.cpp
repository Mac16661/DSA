class Solution {
public:
    struct DSU {
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            for(int i=1; i<=n; i++) parent[i] = i;
        }

        int find(int x) {
            if(parent[x] != x) {
                parent[x] = find(parent[x]); // compressing path
            }

            return parent[x];
        }

        bool unite(int x, int y) {
            int px = find(x), py = find(y);
            if(px == py) return false; // cycle detected(if ultimate parents are same)

            if(rank[px] < rank[py]) swap(px, py);
            parent[py] = px;
            if(rank[px]== rank[py]) rank[px]++;
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        vector<int> ans;
        for(auto &e:edges) {
            int u = e[0], v = e[1];
            if(!dsu.unite(u,v)) ans = e; // we need to send the last one if multiple of them exists
        }

        return ans;
    }
};