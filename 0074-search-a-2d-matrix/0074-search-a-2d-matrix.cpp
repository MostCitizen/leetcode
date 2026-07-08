class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rowL = 0;
        int rowR = m-1;
        int colL = 0;
        int colR = n-1;
        while(rowL <= rowR){
            int rowM = rowL + (rowR - rowL) /2;
            if(matrix[rowM][0] == target) return true;
            else if(matrix[rowM][0] < target && target <= matrix[rowM][colR]){
                while(colL <= colR){
                    int colM = colL + (colR - colL) /2;
                    if(matrix[rowM][colM] == target) return true;
                    else if(colM-1 >= 0 && matrix[rowM][colM-1] < target && target < matrix[rowM][colM]){
                        return false;
                    }
                    else if(matrix[rowM][colM] > target) {
                        if(colR == colM) colR--;
                        else colR = colM;
                    }
                    else if(matrix[rowM][colM] < target){
                        if(colL == colM) colR++;
                        else colL = colM;
                    }
                }
                return false;
            }
            else if(matrix[rowM][0] > target){
                if(rowR == rowM) rowR--;
                else rowR = rowM;
            }
            else {
                if(rowL == rowM) rowL++;
                else rowL = rowM;
            }
        }
        return false;
    }
};