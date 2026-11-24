class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board) {

        int n = board.size();
        int j = col - 1;

        while(j >= 0) {
            if(board[row][j] == 'Q')
                return false;

            j--;
        }

        int i = row - 1;
        j = col - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // 3. Check lower-left diagonal
        i = row + 1;
        j = col - 1;

        while(i < n && j >= 0) {
            if(board[i][j] == 'Q')
                return false;

            i++;
            j--;
        }

        return true;
    }

    void solve(int col,vector<vector<string>>& ans, vector<string>&board, int n ){
        if(col ==n ){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';

                solve(col+1, ans , board, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // vector<string>board(n , '.');  // not work 
        vector<string> board(n, string(n, '.')); // corrected
        
        solve(0, ans, board, n);
        return ans;
    }
};