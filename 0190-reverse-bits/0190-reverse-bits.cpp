class Solution {
public:
    int reverseBits(int n) {
        long long l = 1, h = pow(2, 31);
        int res = 0;
        for(int i=0;i<32;i++){
            int lb = n / h;
            res += lb * l;
            l *= 2;
            n %= h;
            h /= 2;
        }
        return res;
    }
};