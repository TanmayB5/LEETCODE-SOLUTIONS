class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        // Calculate the sum of the first window of size k
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Initialize the maximum sum as the sum of the first window
        int maxSum = sum;

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i]; // Update the sum by removing the first element of the window and adding the next element
            maxSum = max(maxSum, sum); // Update the maximum sum if the current sum is greater
        }

        // Return the maximum average (forcing floating-point division)
        return (1.0 * maxSum) / k;
    }
};
