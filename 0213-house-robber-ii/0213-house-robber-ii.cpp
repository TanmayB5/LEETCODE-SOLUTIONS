class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1 =0;
        int curr1=0;
        int next1=0;
        if(n==0){return nums[0];}
        for(int i=0;i<n-1;i++){
            next1=max(curr1,prev1+nums[i]);
           prev1=curr1;
            curr1=next1;
            
        }

         int prev2 =0;
        int curr2=0;
        int next2=0;
        for(int i=1;i<n;i++){
            next2=max(curr2,prev2+nums[i]);
            prev2=curr2;
            curr2=next2;
            
        }
        
        return max(curr1,curr2);
    }
};