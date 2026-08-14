class Solution {
public:
    int maximumLengthSubstring(string s) {
        int m = 0;
        int length = 0;
        int start = 0;
        unordered_map<int, int> mp;

        for(int i=0;i<s.size();i++){
            length++;
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                length--;
                mp[s[start]]--;
                start++;
            }
            m = max(m, length);
        }
        return m;
    }
};