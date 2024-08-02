class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
            sum1= sum1 + nums[i];
            } else {
                continue;
            }
        }
        for(int i=1;i<n;i++){
             if(i%2!=0){
            sum2= sum2 + nums[i];
            } else {
                continue;
            }
        }
        return max(sum1,sum2);
    }
};