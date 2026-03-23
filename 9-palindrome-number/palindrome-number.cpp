class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        int temp = x;
        long long store = 0;
        while(temp) {
            store = store * 10;
            store += temp%10;
            temp /=10;
        }

        return store== 1ll * x;
    }
};