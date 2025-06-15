class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int n = nums.size();

        // Sorting the array using insertion sort
        for (int i = 0; i <= n - 1; i++) {
            int j = i;
            while (j > 0 && nums[j - 1] > nums[j]) {
                // Swap elements to sort the array
                int temp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = temp;
                j--;
            }
        }

        // XOR all the elements
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ nums[i];
        }

        return xorr;
    }
};