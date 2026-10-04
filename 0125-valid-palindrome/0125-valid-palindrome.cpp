class Solution {
public:
    bool isPalindrome(string s) {
        int index = 0;
        for(int i=0;i<s.size();i++){
            s[i] = tolower(s[i]);
            if((s[i] < 'a' || s[i] > 'z') && 
                (s[i] < '0' || s[i] > '9')) continue;
            s[index++] = s[i];
        }
        s.resize(index);
        int left = 0, right = s.size()-1;
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};