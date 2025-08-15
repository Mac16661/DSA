class Solution {
public:
    bool checkPerfectNumber(int num) {
        if( num==6 or num==28 or num==496 or num==8128 or num==33550336) return true;

        return false;
    }
};