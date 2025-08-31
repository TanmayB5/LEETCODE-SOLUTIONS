class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        for(int i=0;i<n;i++){
            temp = temp^nums[i];
        }

        for(int i=0;i<=n;i++){
            temp = temp^i;
        }
        return temp;
    }
};