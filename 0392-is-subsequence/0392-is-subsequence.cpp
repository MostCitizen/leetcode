class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        int size = s.size();
        for(int i=0;i<t.size();i++){
            if(s[index] == t[i]){
                index++;
            }
            if(index == size) break;
        }
        return index == size;
    }
};