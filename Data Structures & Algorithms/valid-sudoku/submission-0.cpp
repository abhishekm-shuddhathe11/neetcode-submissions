class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                char digit = board[i][j];

                // Ignore empty cells
                if (digit == '.') {
                    continue;
                }

                // Check the row
                for (int k = 0; k < n; k++) {
                    if (k != j && board[i][k] == digit) {
                        return false;
                    }
                }

                // Check the column
                for (int k = 0; k < n; k++) {
                    if (k != i && board[k][j] == digit) {
                        return false;
                    }
                }

                // Check the 3×3 box
                int rowStart = (i / 3) * 3;
                int colStart = (j / 3) * 3;

                for (int r = rowStart; r < rowStart + 3; r++) {
                    for (int c = colStart; c < colStart + 3; c++) {

                        // Skip the current cell
                        if (r == i && c == j) {
                            continue;
                        }

                        if (board[r][c] == digit) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};