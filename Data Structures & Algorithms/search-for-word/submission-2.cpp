class Solution {
public:

    bool dfs( int idx, int row, int col, int rows, int cols,vector<vector<char>>& board, string &word,              vector<vector<bool>> &visited) {

        if( idx == word.length())  return true;

        if( row<0 || row>=rows || col <0 || col>=cols || board[row][col] != word[idx] || visited[row][col]){
            return false;
        }

        visited[row][col] = true;

        bool found = dfs(idx+1, row-1, col, rows, cols, board, word, visited) || 
                     dfs(idx+1, row, col+1, rows, cols, board, word, visited) || 
                     dfs(idx+1, row+1, col, rows, cols, board, word, visited) || 
                     dfs(idx+1, row, col-1, rows, cols, board, word, visited);

        visited[row][col] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size() == 0) return false;

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>( cols, false));

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){

                if( dfs(0, r, c, rows, cols, board, word, visited) ) {
                    return true;
                }
            }
        }
        return false;
    }
};
