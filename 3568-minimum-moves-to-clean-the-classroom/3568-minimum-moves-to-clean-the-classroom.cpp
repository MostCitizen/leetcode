class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int r = 0, c = 0;
        int litterCount = 0;
        vector<vector<int>> L(m, vector<int>(n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j] == 'L'){
                    L[i][j] = litterCount++;
                }else if(classroom[i][j] == 'S'){
                    r=i;
                    c=j;
                }
            }
        }
        struct State {
            int r;
            int c;
            int energy;
            int mask;
            int moves;
        };
        queue<State> q;
        q.push({r, c, energy, 0, 0});

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );
        int allMask = (1 << litterCount) - 1;

        visited[r][c][energy][0] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            State cur = q.front();
            q.pop();
            if (cur.mask == allMask) {
                return cur.moves;
            }

            for(int i=0;i<4;i++){
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                if (classroom[nr][nc] == 'X') {
                    continue;
                }
                int newEnergy = cur.energy - 1;
                if (newEnergy < 0) {
                    continue;
                }
                if(classroom[nr][nc] == 'R') newEnergy = energy;
                
                int newMask = cur.mask;
                if (classroom[nr][nc] == 'L') {
                    int index = L[nr][nc];
                    newMask |= (1 << index);
                }
                if (visited[nr][nc][newEnergy][newMask]) {
                    continue;
                }
                visited[nr][nc][newEnergy][newMask] = true;
                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    cur.moves + 1
                });
            }
        }

        return -1;
    }
};