class Solution {
public:
    void backtrack(vector<int>& digits, vector<bool>& used, vector<int>& current, set<int>& result) {
        if (current.size() == 3) {
            int number = current[0] * 100 + current[1] * 10 + current[2];
            if (number % 2 == 0) result.insert(number);
            return;
        }

        for (int i = 0; i < digits.size(); ++i) {
            if (used[i]) continue;
            if (current.empty() && digits[i] == 0) continue; // No leading zero

            used[i] = true;
            current.push_back(digits[i]);
            backtrack(digits, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        set<int> result;
        vector<bool> used(digits.size(), false);
        vector<int> current;

        backtrack(digits, used, current, result);
        return result.size();
    }
};