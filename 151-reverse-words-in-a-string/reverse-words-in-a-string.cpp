class Solution {
public:
    string reverseWords(string s) {
        // string ans;
        // int left=0;
        // int right = 0;

        // // trim down all the whitespace from start;
        //  while (right < s.size() && s[right] == ' ') right++;
        // s = s.substr(right);

        // // Reset pointers
        // left = 0;
        // right = 0;

        // while (right < s.size()) {
        //     if (s[right] == ' ') {
        //         // Extract the word (length = right - left)
        //         string word = s.substr(left, right - left);
        //         if (!word.empty()) {
        //             ans = word + " " + ans;
        //         }
        //         // Skip whitespaces
        //         while (right < s.size() && s[right] == ' ') right++;
        //         left = right;
        //     } else {
        //         right++;
        //     }
        // }

        // if (left < s.size()) {
        // string word = s.substr(left, right - left);
        //     ans = word + " " + ans;
        // }

        // // Trim trailing space
        // if (!ans.empty() && ans.back() == ' ') {
        //     ans.pop_back();
        // }

        // return ans;

        stringstream ss(s);
        string word, ans;

        while (ss >> word) { // this skips multiple spaces automatically
            if (!ans.empty()) {
                ans = word + " " + ans;
            } else {
                ans = word;
            }
        }

        return ans;

    }
};