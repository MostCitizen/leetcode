class Solution {
  bool searchMatrix(List<List<int>> matrix, int target) {
    int lr = 0, rr = matrix.length-1;
    int lc = 0, rc = matrix[0].length-1;
    while(lr <= rr){
        int midRow = (rr + lr) ~/2;
        if(matrix[midRow][0] <= target && (midRow+1 == matrix.length || target < matrix[midRow+1][0])){
            while(lc <= rc){
                int midCol = (rc + lc) ~/2;
                if(matrix[midRow][midCol] == target){
                    return true;
                }
                else if(matrix[midRow][midCol] < target){
                    lc = midCol + 1;
                }
                else {
                    rc = midCol - 1;
                }
            }
            return false;
        }
        else if(matrix[midRow][0] < target){
            lr = midRow + 1;
        }
        else {
            rr = midRow - 1;
        }
    }
    return false;
  }
}