class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){return 0;}
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}

        vector<int> dp1(n+2,0);
        vector<int> dp2(n+2,0);

        for(int i=n-1;i>0;i--){
            dp1[i] = max(dp1[i+1],nums[i]+dp1[i+2]);
        }

        for(int i=n-2;i>=0;i--){
            dp2[i] = max(dp2[i+1],nums[i]+dp2[i+2]);
        }

        return max(dp1[1],dp2[0]);
    }
};