class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size()) return;
        else if(grid[row][col] == '0') return;
        grid[row][col] = '0';
        DFS(grid, row+1, col);
        DFS(grid, row-1, col);
        DFS(grid, row, col+1);
        DFS(grid, row, col-1);
    }
};