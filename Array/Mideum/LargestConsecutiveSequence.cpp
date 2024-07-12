#include<bits/stdc++.h>
using namespace std;

// TODO: Brute -> 2 for loops to travers and check if(arr[i]-1 == lastsmall)

// TODO: better -> sort the arr and check in one pass that arr[i]-1 == lassmall

// TODO: Optimal -> use set ds to push all the elements and check  if arr[i]-1 is present inside the set
int LongestConsecutiveSeq(vector<int> arr) {
    int n = arr.size();
    int maxCount=0,count=1;

    unordered_set<int> st;

    for(int i=0; i<n; i++) {
        st.insert(arr[i]);
    }

    for(int i=0; i<n; i++) {
        int curr = arr[i];

        while( st.find(curr-1) != st.end()){
            curr=curr-1;
            count++;
        }
        maxCount = max(count,maxCount);
        count=1;
    }

    return maxCount;
}

int main() {
    vector<int> a = {3, 8, 5, 7, 6};
    int ans = LongestConsecutiveSeq(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}