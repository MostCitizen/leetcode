class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        int m = max({a, b, c});
        while(m){
            if(c & 1){
                count += !((a & 1) || (b & 1));
            }else {
                if(a & 1 && b & 1){
                    count += 2;
                }else if(a & 1 || b & 1){
                    count++;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
            m >>= 1;
        }
        return count;
    }
};