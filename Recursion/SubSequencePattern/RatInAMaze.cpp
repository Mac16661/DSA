#include<bits/stdc++.h>
using namespace std;

bool pathFinder(vector<vector<int>> Maze, vector<vector<int>> &ans, int i, int j) {
    int n = Maze.size()-1;
    int m = Maze[0].size()-1;
    

    // Base case (when i & j reaches (n,m))
    if(i == n && j == m) {
        ans[i][j] = 1;
        return true;
    }

    // Check downward
    if((i+1) <= n && Maze[i+1][j] == 1){
        if(pathFinder(Maze, ans, i+1, j) == true){
            ans[i+1][j] = 1;
            return true;
        }
    }

    // Check right
    if(j+1 <= m && Maze[i][j+1] == 1) {
        if(pathFinder(Maze, ans, i, j+1) == true){
            ans[i][j+1] = 1;
            return true;
        }
    }

    // Check left
    if(j-1 >= 0 && Maze[i][j-1] == 1) {
        if(pathFinder(Maze, ans, i, j-1) == true){
            ans[i][j-1] = 1;
            return true;
        }
    }

    return false;
}



int main() {
    int n = 4;

    vector < vector < int >> Maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<vector< int >> ans = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    // Setting row[0] col[0] = 1 because below we are checking form i+1 and pushing it into the ans
    ans[0][0] = 1;

    cout<<pathFinder(Maze, ans, 0, 0)<<endl;

    for(auto i:ans) {
        for(auto j: i) {
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}