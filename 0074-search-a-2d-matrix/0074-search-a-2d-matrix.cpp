class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[mid][0] <= target && target <= matrix[mid][n-1]){
                left = 0;
                right = n-1;
                while(left <= right){
                    int colMid = (left + right) / 2;
                    if(matrix[mid][colMid] == target){
                        return true;
                    }else if(matrix[mid][colMid] < target){
                        left = colMid + 1;
                    }else {
                        right = colMid - 1;
                    }
                }
                return false;
            }else if(matrix[mid][0] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return false;
    }
};