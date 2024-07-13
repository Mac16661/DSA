class Solution {
public:

    void helper(string &num, long long target, int ind, long long prevOperand, long long currentTotal, vector<string> &ans, string temp) {
    // Base condition to return if it is the last element
    if (ind == num.size()) {
        if (currentTotal == target) {
            ans.push_back(temp);
        }
        return;
    }

    for (int len = 1; len <= num.size() - ind; ++len) {
        string part = num.substr(ind, len);
        // Skip leading zeros
        if (part.size() > 1 && part[0] == '0') continue;

        long long currentOperand = stoll(part);

        if (ind == 0) {
            // First number, pick it without any operator
            helper(num, target, ind + len, currentOperand, currentTotal + currentOperand, ans, temp + part);
        } else {
            helper(num, target, ind + len, currentOperand, currentTotal + currentOperand, ans, temp + "+" + part);
            helper(num, target, ind + len, -currentOperand, currentTotal - currentOperand, ans, temp + "-" + part);
            helper(num, target, ind + len, prevOperand * currentOperand, currentTotal - prevOperand + prevOperand * currentOperand, ans, temp + "*" + part);
        }
    }
}


    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, ans, "");
        return ans;
    }
};