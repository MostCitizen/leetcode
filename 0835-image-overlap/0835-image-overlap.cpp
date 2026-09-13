class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = 0;
        for(int dx=-(n-1);dx<=(n-1);dx++){
            for(int dy=-(n-1);dy<=(n-1);dy++){
                m = max(m, findOverlap(img1, img2, dx, dy));
            }
        }
        return m;
    }

    int findOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int dx, int dy){
        int n = img1.size();
        int count = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!img2[i][j]) continue;
                int ni = i + dx;
                int nj = j + dy;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n){
                    if(img1[ni][nj] == img2[i][j]) count++;
                }
            }
        }
        return count;
    }
};