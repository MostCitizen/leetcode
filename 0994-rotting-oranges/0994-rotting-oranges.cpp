class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            bool isChange = false;
            for(int i=0;i<size;i++){
                auto [r, c] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(grid[nr][nc] == 1){
                        isChange = true;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            if(isChange) count++;
        }
        return fresh ? -1 : count;
    }
};