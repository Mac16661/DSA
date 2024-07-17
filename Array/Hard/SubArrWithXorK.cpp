#include<bits/stdc++.h>
using namespace std;

// Brute force approach 
int subarraysWithXorK(vector<int> a, int k) {
    int cnt = 0;
    for(int i=0; i<a.size(); i++) {
        int sum=0;
        for(int j=i; j<a.size(); j++) {
            sum = sum ^ a[j];
            // cout<<sum<<" ";
            if(sum == k) {
                cnt++;  
            }
        } 
        cout<<endl;
    }

    return cnt;
}

// Optimal approach
int subarraysWithXorKOptimal(vector<int> a, int k) {
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++; //{0,1}
    int cnt = 0;

    for(int i=0; i<a.size(); i++){
        xr = xr ^ a[i];

        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;

}

int main() {

    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorKOptimal(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}