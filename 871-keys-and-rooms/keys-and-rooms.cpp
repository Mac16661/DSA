class Solution {
public:
    void dfs(int node, vector<vector<int>>& matrix, vector<bool>& visited) {
        
        for(int i=0; i<matrix[0].size(); i++) {
            if(matrix[node][i] == 1 && visited[i] == false) {
                visited[i] = true;
                dfs(i, matrix, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        // directed graph
        for(int i=0; i<rooms.size(); i++) {
            for(int j = 0; j<rooms[i].size(); j++) {
                cout<<i<<" "<<j<<endl;
                int idx = rooms[i][j];
                matrix[i][idx] = 1; 
            }
        }   

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout<<matrix[i][j]<< " ";
        //     }
        //     cout<<endl;
        // }

        vector<bool> visited(n, false);
        visited[0] = true;

        dfs(0, matrix, visited);

        // loop through visited
        for(auto v: visited) {
            if(v == false) return false;
        }

        return true;
    }
};