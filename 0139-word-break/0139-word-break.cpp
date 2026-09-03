class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1);
        dp[0] = true;
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            for(int j=i+1;j<=n;j++){
                string word = s.substr(i, j-i);
                if(dict.contains(word)) {
                    dp[j] = true;
                }
            }
        }
        return dp[n];
    }
};