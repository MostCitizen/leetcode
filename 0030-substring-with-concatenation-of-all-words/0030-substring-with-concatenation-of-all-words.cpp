class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = s.size();
        int n = words.size();
        int wordLen = words[0].size();
        int total = n * wordLen;
        if(total > m) return {};
        vector<int> res;
        unordered_map<string, int> need;
        for(int i=0;i<n;i++){
            need[words[i]]++;
        }
        for(int start=0;start<wordLen;start++){
            int left = start;
            int count = 0;
            unordered_map<string, int> windows;
            for (int right=start;right+wordLen<=m;right+=wordLen){
                string sub = s.substr(right, wordLen);
                if(need[sub] > 0){
                    count++;
                    windows[sub]++;
                }else {
                    windows.clear();
                    count = 0;
                    left = right + wordLen;
                }
                while(need[sub] < windows[sub]){
                    string leftSub = s.substr(left, wordLen);
                    left += wordLen;
                    windows[leftSub]--;
                    count--;
                }

                if(count == n){
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};