#include<bits/stdc++.h>
using namespace std;

// TODO: Brute approach
int nCr(int n, int r) {
    int ans = 1;
    for(int i=0; i<r; i++) {
        ans = ans * (n-i);
        ans = ans / (i+1);
    }

    return ans;
}

// TODO: Optimal approach
vector<int> pascalTriangle(int n) {
    long long ans = 1;
    vector<int> temp;

    // For printing 1
    temp.push_back(ans);

    for(int i=1; i<n; i++) {
        ans = ans * (n-i);
        ans = ans / i;
        temp.push_back(ans);
    }

    return temp;
}

int main() {
    int n = 5, r =3;

    // Variation 1: Give the nth row and rth col of pascal triangle
    // cout<<nCr(n-1, r-1)<<endl;

    // Variation 2: Print the nth row of pascal triangle
    // vector<int> ans = pascalTriangle(5);
    // for(auto i: ans) cout<<i<<" ";
    // cout<<endl;

    // Variation 3: Printing the whole pascal triangle
    vector<vector<int>> ans;

    for(int i=1; i<=5; i++) {
        ans.push_back(pascalTriangle(i));
    }

    for(auto i: ans){
        for(auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}