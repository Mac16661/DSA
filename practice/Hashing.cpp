#include<bits/stdc++.h>
using namespace std;

map<int, int> countFreq(vector<int> &arr){
    map<int, int> mp;

    for(int i=0; i<arr.size(); i++) {
        mp[arr[i]]++;
    }

    return mp;
}

void Frequency(vector<int> &arr) {
    unordered_map<int, int> mp;

    for(int i=0; i<arr.size(); i++) {
        mp[arr[i]]++; // creating freq map
    }

    int min=0; int minFreq=INT_MAX;
    int max=0; int maxFreq=0;

    for(auto it: mp){
        if(it.second > maxFreq){
            maxFreq = it.second;
            max = it.first;
        }

        if(it.second < minFreq){
            minFreq = it.second;
            min = it.first;
        }
    }

    cout<< "MAX ELEMENT: "<<max<<" -> "<<maxFreq<<endl;
    cout<< "MIN ELEMENT: "<<min<<" -> "<<minFreq<<endl;
}

int main() {
    vector<int> arr = {10,5,10,15,10,5};

    map<int, int> ans = countFreq(arr);
    

    for(auto it: ans){
        cout<<it.first<<" -> "<<it.second<<endl;
    }

    Frequency(arr);
}