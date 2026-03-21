class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        mp[0] = -1;
        int rem = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rem = sum % k;
            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] > 1) {
                    return true;
                }
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};