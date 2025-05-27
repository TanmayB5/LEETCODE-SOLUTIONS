class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    island++;  // Only count when new island is found
                }
            }
        }

        return island;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return;

        grid[r][c] = '0';  // Mark as visited

        dfs(grid, r - 1, c);  // up
        dfs(grid, r + 1, c);  // down
        dfs(grid, r, c - 1);  // left
        dfs(grid, r, c + 1);  // right
    }
};
