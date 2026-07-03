class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix);
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(res[i][j] != 0)
                    res[i][j] = matrix[i][j];
                if(matrix[i][j] == 0){
                    for(int k=0;k<n;k++){
                        res[i][k] = 0;
                    }
                    for(int k=0;k<m;k++){
                        res[k][j] = 0;
                    }
                }
            }
        }
        matrix = res;
    }
};