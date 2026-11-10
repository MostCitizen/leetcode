class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l <= r){
            int m = (l + r) / 2;
            long long po = (long long)m * m;
            if(po == x){
                return m;
            }else if(po < x){
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        return r;
    }
};