class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string common_prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        string word = strs[i];
        int j = 0;
        while (j < word.length() && j < common_prefix.length() && common_prefix[j] == word[j]) {
            j++; 
        }
        common_prefix = common_prefix.substr(0, j); 
        if (common_prefix.empty()) break; 
    }

    return common_prefix;
}
};