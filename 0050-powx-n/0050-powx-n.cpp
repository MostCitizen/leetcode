class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return x;
        else if(n == 0) return 1;
        else if(n < 0){
            double res = 1;
            double cal = x;
            while(n < 0){
                if(n % 2 == -1){
                    res *= cal;
                }
                cal *= cal;
                n /= 2;
            }
            return 1/res;
        }else {
            double res = 1;
            double cal = x;
            while(n > 0){
                if(n % 2 == 1){
                    res *= cal;
                }
                cal *= cal;
                n /= 2;
            }
            return res;
        }
    }
};