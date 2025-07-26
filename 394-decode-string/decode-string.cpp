class Solution {
public:
    void helper(int idx, string& s) {
        if (idx >= s.size()) return;

        if (isdigit(s[idx])) {
            int times = 0;
            // parse the full number (handles multi-digit like "12[ab]")
            while (idx < s.size() && isdigit(s[idx])) {
                times = times * 10 + (s[idx] - '0');
                idx++;
            }

            if (idx >= s.size() || s[idx] != '[') return;

            int start = ++idx; // skip '['
            int openBrackets = 1;
            while (idx < s.size() && openBrackets > 0) {
                if (s[idx] == '[') openBrackets++;
                else if (s[idx] == ']') openBrackets--;
                idx++;
            }

            int end = idx - 1; // position of matching ']'
            string mid = s.substr(start, end - start);
            string decoded = "";
            for (int i = 0; i < times; ++i) decoded += mid;

            // build new string and recurse from the start
            s = s.substr(0, start - to_string(times).size() - 1) + decoded + s.substr(end + 1);
            helper(0, s); // restart since the string has changed
        } else {
            helper(idx + 1, s);
        }
    }

    string decodeString(string s) {
        helper(0, s);
        return s;
    }
};
