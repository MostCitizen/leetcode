class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++){
            char c = 'z' - s[i] + 1;
            res += (c * (i+1));
        }
        return res;
    }
};