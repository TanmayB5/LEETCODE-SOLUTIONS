class Solution {
public:
    int hammingWeight(int n) {
        int ans =1;
        int temp =0;
        while(n!=1){
            temp = n%2;
            if(temp==1){
                ans++;
            }
            n=n/2;
        }
        return ans;
    }
};