#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {2,2,2,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int> mp;
    
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }

    for(auto i : mp){
        cout<<i.first << " -> "<<i.second<<endl;
    }
    return 0;
}