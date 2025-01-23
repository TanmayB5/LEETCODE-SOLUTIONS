class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0;
        int cntz=0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                if(nums[i]<0){neg++;}
                else {cntz++;}
            }
            else {
                break;
            }
        }
        return max(neg,n-neg-cntz);
    }
};