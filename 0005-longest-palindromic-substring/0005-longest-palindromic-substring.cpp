class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 2){
            string res = "";
            res += (n == 1 ? s : (s[0] == s[1] ? s : string(1,s[0])));
            return res;
        }
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        int maxLen = 1;
        int start = 0;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && (len <= 2 || dp[i+1][j-1]);
                if(dp[i][j] && j - i + 1 > maxLen){
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};