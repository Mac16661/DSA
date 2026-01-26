class Solution {
public:
    int reverseBits(int n) {
        int total = 32;
        for (int i = 0; i < total / 2; i++) {
            n = swapBits(n, i, total - i - 1);
        }
        return n;
    }

    int swapBits(int n, int i, int j) {
        int lo = (n >> i) & 1;
        int hi = (n >> j) & 1;
        if((lo ^ hi) == 1) { //both bits are different so need to swap
            n ^= ((1 << i) | (1 << j));
        }
        return n;
    }
};