class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col;
        set<int> row;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int r : row){
            for(int i=0;i<n;i++){
                matrix[r][i] = 0;
            }
        }
        for(int c : col){
            for(int i=0;i<m;i++){
                matrix[i][c] = 0;
            }
        }
    }
};