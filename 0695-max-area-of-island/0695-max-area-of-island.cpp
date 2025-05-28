class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        int maxarea = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, vis, i, j, area);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }

private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int& area) {
        int row = grid.size();
        int col = grid[0].size();
        
        // Boundary and condition checks
        if (i < 0 || i >= row || j < 0 || j >= col || vis[i][j] || grid[i][j] == 0)
            return;

        vis[i][j] = true;
        area++;

        // Explore all 4 directions
        dfs(grid, vis, i + 1, j, area);
        dfs(grid, vis, i - 1, j, area);
        dfs(grid, vis, i, j + 1, area);
        dfs(grid, vis, i, j - 1, area);
    }
};
