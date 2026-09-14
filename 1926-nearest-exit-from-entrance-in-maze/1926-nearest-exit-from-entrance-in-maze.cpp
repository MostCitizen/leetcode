class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            count++;
            while(size--){
                auto [r, c] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= row || nc <0 || nc >= col){
                        continue;
                    }else if(maze[nr][nc] == '+' || visited[nr][nc]){
                        continue;
                    }else if (nr==0 || nr==row-1 || nc==0 || nc==col-1){
                        return count;
                    }
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};