class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    visit(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void visit(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return;
        else if(grid[r][c] == '0') return;
        grid[r][c] = '0';
        visit(grid, r-1, c);
        visit(grid, r+1, c);
        visit(grid, r, c-1);
        visit(grid, r, c+1);
        return;
    }
};