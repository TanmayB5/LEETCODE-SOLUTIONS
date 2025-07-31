class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            int x1 = bombs[i][0] , y1 = bombs[i][1] , r1 = bombs[i][2];
            for(int j=i+1;j<n;j++){
                int x2 =bombs[j][0] , y2=bombs[j][1] , r2 = bombs[j][2];
                long long d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                if (d <= (long long) r1 * r1) adj[i].push_back(j);
                if (d <= (long long) r2 * r2) adj[j].push_back(i);
            } 
         }
        int res=0;
        for(int i=0;i<n;i++){
         vector<int> visited(n,0);
         stack<int> stk;
         stk.push(i);
         visited[i] = 1;
         int count =1;

         while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            for(auto nei : adj[node]){
                if(visited[nei]==0){
                    visited[nei] =1;
                    stk.push(nei);
                    count++;
                }
            }
         }
         res = max(res,count);
        }
        return res;
    }
};