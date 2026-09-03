class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int m = 0;
        for(int i=0;i<points.size();i++){
            map<pair<int, int>, int> map;
            for(int j=i+1;j<points.size();j++){
                int dx = points[i][0]-points[j][0];
                int dy = points[i][1]-points[j][1];
                int g = gcd(abs(dy), abs(dx));
                dx /= g;
                dy /= g;
                
                if(dx < 0 || (dy == 0 && dx < 0) || (dx == 0 && dy < 0)){
                    dx = -dx;
                    dy = -dy;
                }
                map[{dy, dx}] += 1;
                m = max(m, map[{dy, dx}]);
            }
        }
        return m+1;
    }
};