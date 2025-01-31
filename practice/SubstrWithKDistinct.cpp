#include<bits/stdc++.h>
using namespace std;

// Brute force
vector<string> strKDist(string s, int k) {
    vector<string> distinct;

    unordered_map<char, int> mp;

    for(int i=0; i<s.length(); i++) {
        mp.clear();
        for(int j=i; j<s.length(); j++) {
            mp[s[j]]++;

            if(mp.size() == k) {
                string substring = s.substr(i, (j-i)+1);
                distinct.push_back(substring);
            }
        }
    }
    return distinct;
}



int main() {
    string s = "cdad";
    vector<string> distK = strKDist(s, 4);

    for(auto dist: distK){
        cout<<dist<<" ";
    }

    cout<<endl;
    
    return 0;
}
