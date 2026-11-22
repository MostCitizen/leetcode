class Solution {
public:
    bool checkString(string s) {
        int lastA = -1;
        int firstB = -1;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a'){
                lastA = i;
            }else if(firstB == -1){
                firstB = i;
            }
        }
        return firstB == -1 || lastA < firstB;
    }
};