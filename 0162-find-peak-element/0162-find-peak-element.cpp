class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        for (int i = 1; i <= (n - 2) / 2; i++) {

            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;

            int j = n - 1 - i;
            if (j != i && nums[j] > nums[j - 1] && nums[j] > nums[j + 1])
                return j;
        }

        if (n % 2 == 1) {
            int mid = n / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
        }

        return -1;
    }
};
