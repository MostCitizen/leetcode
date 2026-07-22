class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int x = points[0][1];
        int res = 0;
        for(int i=1;i<points.size();i++){
            if(points[i][0] > x || x > points[i][1]){
                res++;
                x = points[i][1];  
            }
        }
        return res + 1;
    }
};