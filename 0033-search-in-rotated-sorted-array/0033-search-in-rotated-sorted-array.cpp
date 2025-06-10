class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        // Find pivot point (smallest element)
        while (l < r) {  // Changed from l <= r to l < r
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int pivot = l;
        
        // Search in first half [0, pivot-1]
        int result = binarysearch(nums, target, 0, pivot - 1);
        if (result != -1) {
            return result;
        }
        
        // Search in second half [pivot, nums.size()-1]
        return binarysearch(nums, target, pivot, nums.size() - 1);
    }

private:
    int binarysearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {  // Moved the condition to while loop
            int mid = (l + r) / 2;  // Moved mid calculation inside loop
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};