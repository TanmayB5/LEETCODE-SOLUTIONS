class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9; // Standard Sudoku size is 9x9.

        // Check rows and columns
        for (int i = 0; i < n; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;

            for (int j = 0; j < n; j++) {
                // Check row
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }

                // Check column
                if (board[j][i] != '.') {
                    if (colSet.count(board[j][i])) return false;
                    colSet.insert(board[j][i]);
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_set<char> boxSet;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char current = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (current != '.') {
                            if (boxSet.count(current)) return false;
                            boxSet.insert(current);
                        }
                    }
                }
            }
        }

        return true; // If all checks pass, the board is valid.
    }
};
