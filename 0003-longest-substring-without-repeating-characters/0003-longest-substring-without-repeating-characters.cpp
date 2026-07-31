class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0) return 0;
        int res = 0;
        int left =0, right = 0;
        unordered_map<char, int> map;
        for(;right<size;right++){
            char c = s[right];
            map[c]++;
            while(map[c] > 1){
                map[s[left]]--;
                left++;
            }
            res = max(res, right-left + 1);
        }
        
        return res;
    }
};