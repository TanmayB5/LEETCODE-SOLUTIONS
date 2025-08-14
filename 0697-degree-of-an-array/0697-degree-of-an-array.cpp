class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>freq,first;
        int maxfreq = 0 , minlen = nums.size();

        for(int i=0;i<nums.size();i++){
            if(!first.count(nums[i])){
                first[nums[i]] = i;
            }
            freq[nums[i]]++;

            if(freq[nums[i]]>maxfreq){
                maxfreq = freq[nums[i]];
                minlen = i - first[nums[i]] +1;

            } else if(maxfreq == freq[nums[i]]){
                minlen = min(minlen, i - first[nums[i]] +1);
            }
        }
        return minlen;
    }
};