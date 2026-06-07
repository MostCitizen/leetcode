class Solution {
public:
    string convert(string s){
        string result = "";
        for(int i=0;i<s.size();i++){
            char c = tolower(s[i]);
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                result += c;
            }
        }
        return result;
    }

    bool isPalindrome(string s) {
        int size = s.size();
        if(size == 1) return true;
        s = convert(s);
        size = s.size();
        for(int i=0;i<size/2;i++){
            if(s[i] != s[size-1-i]) return false;
        }
        return true;
    }
};