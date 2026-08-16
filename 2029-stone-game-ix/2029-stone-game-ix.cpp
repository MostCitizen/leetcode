class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> v(3);
        for(int stone : stones){
            v[stone%3]++;
        }
        if(v[0] % 2 == 0) return v[1] > 0 && v[2] > 0;
        return abs(v[1] - v[2]) > 2;
    }
};