class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return nums[0];}
        int ans = INT_MIN;
        int prod = 0;

        for(int i=0;i<n;i++){
            prod = nums[i];
            ans = max(ans,prod);
            for(int j=i+1;j<n;j++){
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }
        return ans;
    }
};