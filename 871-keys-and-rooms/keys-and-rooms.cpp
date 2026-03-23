class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited) {
        
        for(auto room:rooms[node]) {
            if(visited[room] == false) {
                visited[room] = true;
                dfs(room, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) { // we should have cosidered this rooms as adj list
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;

        dfs(0, rooms, visited);

        for( bool v : visited)
        {
            if(!v)
            {
                return false;
            }
        }

        return true;
    }
};