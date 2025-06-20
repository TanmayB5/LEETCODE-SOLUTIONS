class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int low = 1, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = 1LL * mid * mid;  // Safe multiplication

            if (val <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
