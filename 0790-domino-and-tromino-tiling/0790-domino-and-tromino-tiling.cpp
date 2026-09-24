class Solution {
public:
    int numTilings(int n) {
        if(n == 1 || n == 2) return n;
        vector<long long> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        const int MOD = 1000000007;

        for(int i=4;i<=n;i++){
            long long cur = (dp[i-1] * 2 + dp[i-3]) % MOD;
            dp[i] = cur;
        }
        return dp[n];
    }
};