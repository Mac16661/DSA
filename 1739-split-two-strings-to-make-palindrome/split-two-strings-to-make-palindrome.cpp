class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool check(string &a, string &b) {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j]) {
            i++;
            j--;
        }
        // At mismatch: either finish inside a or inside b
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};
