class Solution {
public:

    int count(int i){
        int cnt = 0;
        while(i){
            i = i&i-1;
            cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
    vector<int> ans(n+1,0);

    for(int i=0;i<=n;i++){
      ans[i] = count(i);
    }
    return ans;
    }
};