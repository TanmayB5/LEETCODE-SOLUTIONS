class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int,int>> q;
        int fresh =0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> dir = {{0,1} , {0,-1} ,{1,0} ,{-1,0}};
        while(!q.empty() && fresh>0){
            int len = q.size();
            for(int i=0;i<len;i++){
                auto cur = q.front();
                q.pop();
                int r = cur.first;
                int c = cur.second;
                for(const auto& d : dir){
                    int row = r + d.first;
                    int col = c + d.second;
                    if(row >= 0 && row < grid.size() &&
                        col >= 0 && col < grid[0].size() &&
                        grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                    }
                }
            }
            ans++;
        }


        
        return fresh != 0 ? -1 : ans ;
    }
};