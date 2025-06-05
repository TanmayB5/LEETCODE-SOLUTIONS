class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans =0 ;
        for(int i=0;i<candies.size();i++){
            int temp = candies[i]/k;
            ans += temp;
        }
        return ans;

    }
};