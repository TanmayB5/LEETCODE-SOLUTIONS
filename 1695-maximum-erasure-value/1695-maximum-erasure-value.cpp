class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, l = 0;
        unordered_set<int> st;
        int sum = 0;

        for (int r = 0; r < nums.size(); r++) {

            while (st.find(nums[r]) != st.end()) {
                st.erase(nums[l]);
                sum = sum - nums[l];
                l++;
            }

            st.insert(nums[r]);
            sum = sum + nums[r];

            res = max(res, sum);
        }
        return sum;
    }
};