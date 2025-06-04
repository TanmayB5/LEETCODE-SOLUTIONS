class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-2;
        int j = nums.size()-1;

        while(j>i){
            int sum1 =0 , sum2 =0;

            for(int a=0;a<=i;a++){
                sum1 += nums[a];
            }

            for(int b=j;b<nums.size();b++){
                sum2 += nums[b];
            }

            if(sum1 == sum2){
                return true;
            } else if(sum1>sum2){
                i--;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};