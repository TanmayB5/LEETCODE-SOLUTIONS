class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int i) {
        // Base case: all characters matched
        if (i == word.size()) {
            return true;
        }

        // Boundary and character mismatch check
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || 
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions
        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        // Backtrack: restore the original character
        board[r][c] = temp;

        return found;
    }
};
