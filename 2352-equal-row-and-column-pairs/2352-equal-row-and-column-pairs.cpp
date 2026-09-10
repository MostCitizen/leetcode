class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> c;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(grid[j][i]);
            }
            c.push_back(v);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i] == c[j]) res++;
            }
        }
        return res;
    }
};