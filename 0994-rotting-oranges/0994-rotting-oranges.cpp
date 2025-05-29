class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        int rows = grid.size();
        int cols = grid[0].size();

        // Count fresh oranges and enqueue rotten ones
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // BFS
        while(!q.empty() && fresh > 0) {
            int length = q.size();
            for(int k = 0; k < length; k++) {
                auto [r, c] = q.front(); q.pop();
                for(auto [dr, dc] : dir) {
                    int row = r + dr;
                    int col = c + dc;

                    // Check bounds and if cell has a fresh orange
                    if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row, col});  // Don't forget to add to queue!
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
