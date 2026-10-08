class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int have[26] = {0,};
        for(char c : magazine){
            have[c-'a']++;
        }
        for(char c : ransomNote){
            if(--have[c-'a'] < 0) return false;
        }
        return true;
    }
};