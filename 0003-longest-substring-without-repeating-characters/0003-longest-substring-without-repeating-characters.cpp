class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int count = 0;
        int res = 0;
        int n = s.size();
        int left = 0;
        for(int right=0;right<n;right++){
            count++;
            map[s[right]]++;
            if(map[s[right]] > 1){
                res = max(res, count-1);
            }
            while(map[s[right]] > 1){
                count--;
                map[s[left++]]--;
            }
        }
        res = max(res, count);
        return res;
    }
};