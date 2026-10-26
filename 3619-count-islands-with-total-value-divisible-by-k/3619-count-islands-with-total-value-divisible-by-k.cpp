class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                int sum = 0;
                solve(grid, k, i, j, sum);
                res += (sum % k == 0 ? 1 : 0);
            }
        }
        return res;
    }
    void solve(vector<vector<int>>& grid, int k, int r, int c, int& sum){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return;
        }else if(grid[r][c] == 0){
            return;
        }
        sum = sum % k + grid[r][c];
        grid[r][c] = 0;
        solve(grid, k, r-1, c, sum);
        solve(grid, k, r+1, c, sum);
        solve(grid, k, r, c-1, sum);
        solve(grid, k, r, c+1, sum);
    }
};