class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int y=n-1;
        int x=0;
        vector<vector<int>> res(matrix);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[i][j] = matrix[y-j][x];
            }
            x++;
        }
        matrix = res;
    }
};