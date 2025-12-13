class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        int m = 100000;
        int ans = 0;
        for(int i=0;i<n;i++){
            temp = max(0-nums[i],nums[i]-0);
            if(temp<=m){
                m = temp;
                ans = i;
                if(i>0 && temp==m && nums[i]<nums[i-1] ){
                    ans = i-1;
                }
            }
        }
        return nums[ans];
    }
};