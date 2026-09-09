class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        int disit = 4;
        while(true){
            long long start = pow(10, disit-1);
            long long end = pow(10, disit) - 1;
            if(start > n) break;
            long long count = min((long long)n, end) - start + 1;
            res += count * ((disit - 1) / 3);
            disit++;
        }
        return res;
    }
};