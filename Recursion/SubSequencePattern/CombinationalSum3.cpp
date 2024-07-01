    #include<bits/stdc++.h>
    using namespace std;

    void combi(vector<vector<int>>& ans, vector<int>& subset, int idx, int k, int n){
        if(k == 0 && n == 0){
            ans.push_back(subset);
        }

        for(int i = idx;i<10;i++){
            if(i > idx && i == i-1) continue;
            if(n == 0) break;
            subset.push_back(i);
            combi(ans, subset, i+1, k-1, n-i);
            subset.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;

        combi(ans, subset, 1, k, n);
        return ans;
    }
    
    int main() {
        vector<vector<int>> ans = combinationSum3(3,7);
        return 0;
    }