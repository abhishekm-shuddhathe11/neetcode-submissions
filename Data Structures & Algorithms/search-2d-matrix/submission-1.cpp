class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int rowStart = 0;
        int colStart =m-1;

        while(rowStart < n && colStart >=0) {

            if(matrix[rowStart][colStart] == target ){
                return true;
            }
            else if(matrix[rowStart][colStart] < target){
                rowStart++;
            }
            else{
                colStart--;
            }
        }
        return false;
    }
};
