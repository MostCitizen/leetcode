class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9 * num < sum) return "";
        string res = "";
        for(int i=0;i<num;i++){
            for(int j=9;j>=0;j--){
                if(sum - j >= 0){
                    sum -= j;
                    res += (j + '0');
                    break;
                }
            }
        }
        return res;
    }
};