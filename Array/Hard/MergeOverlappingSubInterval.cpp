#include<bits/stdc++.h>
using namespace std;

// Brute
// void brute(vector<vector<int>> arr) {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;

//     for(int i=0; i<n; i++) {
//         int start = arr[i][0];
//         int end = arr[i][1];

//         if(!ans.empty() && end <= ans.back()[1]) continue;

//         for(int j=i+1; j<n; j++) {
//             if(arr[j][0] <= end) {
//                 end = max(end, arr[j][1]);
//             }else{
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }

// Optimal
vector<vector<int>> Optimal(vector<vector<int>> &arr) {
    int n=arr.size();
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]); // not merging
        }else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]); //merging
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    int n = arr.size();

    arr = Optimal(arr);
    for(auto i:arr){
        cout<<"{ ";
        for(auto j:i){
            cout<<j<<", ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}