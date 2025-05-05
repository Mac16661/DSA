class Solution {
public:
    string removeKdigits(string num, int k) {
    string result = "";

    for (char digit : num) {
        // Remove digits from result while the current digit is smaller
        // and we still have digits to remove
        while (!result.empty() && k > 0 && result.back() > digit) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }

    // Remove remaining digits from the end if k > 0
    while (k-- > 0 && !result.empty()) {
        result.pop_back();
    }

    // Remove leading zeros
    int i = 0;
    while (i < result.size() && result[i] == '0') i++;

    result = result.substr(i);

    return result.empty() ? "0" : result;
   }
};