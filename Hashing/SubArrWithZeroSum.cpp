//Brute force
#include<bits/stdc++.h>
using namespace std;

// int main() {
//     int arr[11] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
//     int n = 11;

//     int count = 0;
    
//     for(int i=0; i<n; i++){

//         for(int j=i; j<n; j++){
//             count = count + arr[j];

//             if(count == 0) cout<<"Subarr "<<i <<" -> "<<j<<endl;
//         }
//         count = 0;

//     }

//     return 0;
// }

int main() {
    int arr[] = {0,0,5,5,0,0};
    int n = 6;

    unordered_map<int, int> mp;

    int sum, ans = 0;

    mp[0] = 1;

    for(int i=0; i<n; i++){
        sum += arr[i];

        if(mp.find(sum) != mp.end()){
            ans += mp[sum];
        }
        mp[sum]++;

    }
    cout<<ans<<endl;
    return 0;
}