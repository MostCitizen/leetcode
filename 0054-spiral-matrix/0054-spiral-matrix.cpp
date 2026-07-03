class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = 0;
        int dx = 1;
        int dy = 0;
        for(int i=0;i<m*n;i++){
            result.push_back(matrix[y][x]);
            matrix[y][x] = 101;
            if(!(0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m) || matrix[y+dy][x+dx] == 101){
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            x+=dx;
            y+=dy;
        }
        return result;
    }
};