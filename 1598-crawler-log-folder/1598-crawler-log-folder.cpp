class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int ans = 0;
        for(int i=0;i<n;i++ ){
            if(logs[i]=="../" ){
                if(ans>0){
                ans = ans - 1;}
            } else if(logs[i]=="./"){
                continue;
            } else {
                ans++;
            }
        }
        return ans<0?0:ans;
    }
};