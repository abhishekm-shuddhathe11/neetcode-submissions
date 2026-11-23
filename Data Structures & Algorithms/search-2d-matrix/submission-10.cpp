// general => Remember: size() gives you the count; size() - 1 gives you the last valid index.

//=======================================================

// Brutte

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//         if (matrix[i][j] == target) {
//             return true;
//         }
//     }
// }
// return false;

//=======================================================================

// Better

// Binary search on every row
// Time: O(nlog m)
//Auxiliary space: (O(1) for iterative binary search.

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         for(int i=0; i<matrix.size(); i++) {

//         int s = 0 , e = matrix[i].size()-1 ;
//             while(s<=e){
//                 int mid = s + (e-s)/2 ;

//                 if(matrix[i][mid] == target ) {
//                     return true;
//                 }
//                 else if(matrix[i][mid] < target) {
//                     s = mid + 1;
//                 }
//                 else {
//                     e = mid -1;
//                 }
//             }
//         }
//         return false;
//     }
// };


// ======================================================================================================

// Optimal (Staircase search)

// Time: (O(n+m))
// Auxiliary space: (O(1)).

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         if (matrix.empty() || matrix[0].empty()) {
//             return false;
//         }

//         int n = matrix.size();
//         int m = matrix[0].size();

//         int rowStart = 0;
//         int colStart =m-1;

//         while(rowStart < n && colStart >=0) {

//             if(matrix[rowStart][colStart] == target ){
//                 return true;
//             }
//             else if(matrix[rowStart][colStart] < target){
//                 rowStart++;
//             }
//             else{
//                 colStart--;
//             }
//         }
//         return false;
//     }
// };



// Bottom-left staircase search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < m) {

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                col++;
            }
            else {
                row--;
            }
        }

        return false;
    }
};