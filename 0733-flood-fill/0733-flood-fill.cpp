class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();  // Get number of columns
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int val = image[sr][sc]; 
        if (!vis[sr][sc] && image[sr][sc] != color) {
    dfs(image, vis, sr, sc, n, m, color, val);
}

        return image;
    }

private:
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& vis, int r, int c, int n, int m, int color, int val) {
    vis[r][c] = true;
    image[r][c] = color;

    if (r - 1 >= 0 && !vis[r - 1][c] && image[r - 1][c] == val)
        dfs(image, vis, r - 1, c, n, m, color, val);

    if (c - 1 >= 0 && !vis[r][c - 1] && image[r][c - 1] == val)
        dfs(image, vis, r, c - 1, n, m, color, val);

    if (r + 1 < n && !vis[r + 1][c] && image[r + 1][c] == val)
        dfs(image, vis, r + 1, c, n, m, color, val);

    if (c + 1 < m && !vis[r][c + 1] && image[r][c + 1] == val)
        dfs(image, vis, r, c + 1, n, m, color, val);
}
};
