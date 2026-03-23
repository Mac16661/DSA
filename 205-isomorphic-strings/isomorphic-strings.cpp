class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Just start mapping one char to another, if matching already exists then check if char is same or not, if not return false (but this will not garuntee order)

        // To maintain order after checking we need to actually map it and at the end check it both are equal

        unordered_map<char, char> mp, mp1;
        for (int i = 0; i < s.size(); i++) {
            if(mp[s[i]] && mp[s[i]] != t[i]) return false;
            if(mp1[t[i]] && mp1[t[i]] != s[i]) return false;

            // if new value then insert in both maps
            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
        }


        return true;
    }
};