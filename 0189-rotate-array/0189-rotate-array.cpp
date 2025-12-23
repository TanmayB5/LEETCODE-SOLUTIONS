class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        if(n ==1){return;}
        if(n==k || k==0){return;}
        if(n<k){
            k = k % n;
        }

        int i = 0;
        int j = k;
        if (n % 2 == 0) {
            for (int j =n- k; j < n; j++) {
                ans.push_back(nums[j]);
            }
            for (int i = 0; i < n - k; i++) {
                ans.push_back(nums[i]);
            }
            for (int i = 0; i < n; i++) {
                nums[i] = ans[i];
            }
        }

        if (n % 2 != 0) {
            for (int j = n-k; j < n; j++) {
                ans.push_back(nums[j]);
            }
            for (int i = 0; i <n- k; i++) {
                ans.push_back(nums[i]);
            }
            for (int i = 0; i < n; i++) {
                nums[i] = ans[i];
            }
        }
    }
};