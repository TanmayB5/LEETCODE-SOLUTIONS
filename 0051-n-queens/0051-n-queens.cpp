class Solution {
public:
    void nqueen(vector<string>& board, vector<vector<string>>& ans, int n,
                int i) {
        if (i == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (issafe(i, j, board)) {
                board[i][j] = 'Q';
                nqueen(board, ans, n, i + 1);
                board[i][j] = '.';
            }
        }
    }

    bool issafe(int r, int c, const vector<string>& board) {
        int n = board.size();

        // check column (upwards)
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q')
                return false;
        }

        // check left diagonal
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // check right diagonal
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueen(board, ans, n, 0);
        return ans;
    }
};