class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true;       // 4^0 = 1
        if (n <= 0 || n % 4 != 0) return false; // not divisible by 4
        return isPowerOfFour(n / 4);
    }
};
