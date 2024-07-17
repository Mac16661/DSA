#include<bits/stdc++.h>
using namespace std;


int main() {
    vector<int> A = {9, -3, 3, -1, 6, -5};
    int n = A.size();

    unordered_map<int,int> mp;
    int sum=0, maxi=0;

    for(int i=0; i<n; i++) {
        sum+= A[i];

        if(sum==0) {
            maxi = i+1;
        }else{
            if(mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
    }

    cout<<maxi<<endl;

    return 0;
}