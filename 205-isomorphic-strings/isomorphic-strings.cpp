class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char, char> mp, mp1;

       for(int i=0; i<s.length(); i++) {
            if(mp[s[i]] && mp[s[i]] != t[i]) return false;
            if(mp1[t[i]] && mp1[t[i]] != s[i]) return false;

            // if new value then insert in both maps
            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
       }

       return true;
    }
};