class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charMap;
        unordered_map<string,char> wordMap;
        vector<string> word;
        string temp = "";
        for(char c : s){
            if(c == ' '){
                if(temp != "")
                    word.push_back(temp);
                temp = "";
            }
            else temp += c;
        }
        if(temp != "")
            word.push_back(temp);
        if(pattern.size() != word.size()) return false;

        for(int i=0;i<word.size();i++){
            char c = pattern[i];
            if(charMap.count(c) != 0){
                if(charMap[c] != word[i]) return false;
            }
            else {
                if(wordMap.count(word[i]) != 0){
                    if(wordMap[word[i]] != c) return false;
                }
                wordMap[word[i]] = c;
                charMap[c] = word[i];
            }
        }
        return true;
    }
};