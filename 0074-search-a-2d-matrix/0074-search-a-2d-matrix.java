class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int low = 0, high = m-1;
        int left = 0, right = n-1;
        while(low <= high){
            int rowMid = (high + low) / 2;
            if(matrix[rowMid][0] <= target && target <= matrix[rowMid][right]){
                while(left <= right){
                    int colMid = (right + left) / 2;
                    if(matrix[rowMid][colMid] == target) return true;
                    else if(matrix[rowMid][colMid] < target){
                        left = colMid + 1;
                    }else {
                        right = colMid - 1;
                    }
                }
            }else if(matrix[rowMid][0] > target){
                high = rowMid - 1;
            }else {
                low = rowMid + 1;
            }
        }
        return false;
    }
}