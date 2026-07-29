// Brutte Approach

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         int n = board.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {

//                 char digit = board[i][j];

//                 // Ignore empty cells
//                 if (digit == '.') {
//                     continue;
//                 }

//                 // Check the row
//                 for (int k = 0; k < n; k++) {
//                     if (k != j && board[i][k] == digit) {
//                         return false;
//                     }
//                 }

//                 // Check the column
//                 for (int k = 0; k < n; k++) {
//                     if (k != i && board[k][j] == digit) {
//                         return false;
//                     }
//                 }

//                 // Check the 3×3 box
//                 int rowStart = (i / 3) * 3;
//                 int colStart = (j / 3) * 3;

//                 for (int r = rowStart; r < rowStart + 3; r++) {
//                     for (int c = colStart; c < colStart + 3; c++) {

//                         // Skip the current cell
//                         if (r == i && c == j) {
//                             continue;
//                         }

//                         if (board[r][c] == digit) {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }

//         return true;
//     }
// };


//==========================================================================================//

// The Most Optimal Solution 

#include<bits/stdc++.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            int n= board.size();

        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char digit = board[i][j];

                if(digit == '.'){
                    continue;
                }

                int index = digit -'1';
                int box = ((i/3)*3) + (j/3);
                if(rows[i][index] == true){
                    return false;
                }
                if(cols[j][index] == true){
                    return false;
                }
                if(boxes[box][index] == true){
                    return false;
                }

                rows[i][index] =true;
                cols[j][index] = true;
                boxes[box][index] = true;
            }
        }
        return true;

    }
};