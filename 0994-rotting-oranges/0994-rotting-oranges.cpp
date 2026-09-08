class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int res = 0;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            bool rotted = false;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                int dr[4] = {-1, 1, 0, 0};
                int dc[4] = {0, 0, -1, 1};
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n
                     || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                    rotted = true;
                }
            }
            if(rotted) res++;
        }
        return fresh != 0 ? -1 : res;
    }
};