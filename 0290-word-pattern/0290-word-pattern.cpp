class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> patternMap;
        int index = 0;
        int len = s.size();
        for(int i=0;i<pattern.size();i++){
            if(index >= len) return false;
            string temp = "";
            while(index < len && s[index] != ' '){
                temp += s[index++];
            }
            index++;
            if(map.contains(pattern[i]) && map[pattern[i]] != temp) {
                return false;
            }
            if(patternMap.contains(temp) && patternMap[temp] != pattern[i]) {
                return false;
            }
            map[pattern[i]] = temp;
            patternMap[temp] = pattern[i];
        }
        return index >= len;
    }
};