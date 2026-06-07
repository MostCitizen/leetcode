class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        vector<string> vS;
        string temp = "";
        for(char c : s){
            if(c != ' ') temp += c;
            else {
                if(temp != "")
                    vS.push_back(temp);
                temp = "";
            }
        }
        if(temp != "")
            vS.push_back(temp);
        return vS.back().size();
    }
};