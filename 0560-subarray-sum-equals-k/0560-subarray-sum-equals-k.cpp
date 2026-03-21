class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixsum;
        int res = 0 , cursum = 0;
        prefixsum[0] = 1;

        for(int i=0;i<nums.size();i++){
            cursum += nums[i];
            int diff = cursum - k;
            res += prefixsum[diff];
            prefixsum[cursum]++;
        }
        return res;
    }
};