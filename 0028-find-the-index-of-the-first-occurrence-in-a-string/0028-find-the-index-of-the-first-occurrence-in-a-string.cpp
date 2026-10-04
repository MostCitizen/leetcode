class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        vector<int> starting;
        for(int i=0;i<m;i++){
            if(haystack[i] == needle[0] && n <= m - i + 1){
                starting.push_back(i);
            }
        }
        for(int start : starting){
            bool isSuccess = true;
            for(int i=0;i<n;i++){
                if(haystack[start + i] != needle[i]){
                    isSuccess = false;
                    break;
                }
            }
            if(isSuccess) return start;
        }
        return -1;
    }
};