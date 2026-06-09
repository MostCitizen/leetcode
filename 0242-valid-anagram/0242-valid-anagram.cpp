class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> word(26);
        for(char c : s){
            word[c-'a']++;
        }
        for(char s : t){
            if(--word[s-'a'] < 0) return false;
        }
        return true;
    }
};