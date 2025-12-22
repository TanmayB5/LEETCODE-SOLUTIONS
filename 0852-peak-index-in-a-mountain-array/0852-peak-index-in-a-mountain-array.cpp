class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int l=0; 
        int r = nums.size()-1;
        int m;
        while(l<r){
             m = l + (r-l)/2;

            if(nums[m]<nums[m+1]){
                l = m+1;
            } else {
                r = m;
            }
        }
        return l;
    }
};