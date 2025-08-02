class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     int globmax = nums[0] , globmin = nums[0];
     int curmax = 0, curmin = 0, total = 0;

     for(auto num : nums){
        curmax = max(curmax+num, num);
        curmin = min(curmin + num, num );
        total += num;
        globmax = max(globmax,curmax);
        globmin = min(globmin,curmin);
     }   
     return globmax>0 ? max(globmax,total-globmin) : globmax;
    }
};