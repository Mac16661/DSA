class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // if(n%2 == 0) {
        //     return {n/2, n/2};
        // }else{
        //     return {n/2, ((n/2) + 1)};
        // }

        for(int i=1; i<=n; i++) {
            if(to_string(n-i).find('0') != string::npos) continue;
            if(to_string(i).find('0') != string::npos) continue;
            if(i+(n-i) == n) return {i,n-i};
        }
        return {};
    }
};