class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle;

        while(true) {
            if(cycle.count(n)) break;

            cycle.insert(n);
            int temp = n;

            int newNumber=0;
            while(temp!=0) {
                int num = temp%10;
                newNumber+= num*num;
                temp/=10;
            }
            n = newNumber;
            if(n==1) return true;
        }

        return false;
    }
};