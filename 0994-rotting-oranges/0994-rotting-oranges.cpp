class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total = 0;
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    total++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            bool isChange = false;
            while(size--){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= row || nc < 0 || nc >= col){
                        continue;
                    }else if(grid[nr][nc] != 1){
                        continue;
                    }
                    total--;
                    isChange = true;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            if(isChange) count++;
        }
        return total != 0 ? -1 : count;
    }
};