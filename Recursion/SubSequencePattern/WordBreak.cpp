#include<bits/stdc++.h>
using namespace std;
// TODO: Most efficient solution require dp
bool partialMatch(string s1, string s2, int ind) {
        for(int i=0; i < s2.size(); i++) {
            if(s1[i+ind] != s2[i]) {
                return false;
            }
        }

        return true;
    }

    bool result;

    bool helper(int ind, string s, vector<string>& wordDict) {
        if(ind == s.length()) return true;

        for(int i=0; i<wordDict.size(); i++) {
            if(partialMatch(s, wordDict[i], ind)) {
                result = result || helper(ind+(wordDict[i].size()), s, wordDict);
            }
        }

        return result || false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(0, s, wordDict);
    }

int main() {
    vector<string> wordDict = {"leet","code"};
    string s = "leetcode";

    cout<<wordBreak(s, wordDict)<<endl;
    return 0;
}