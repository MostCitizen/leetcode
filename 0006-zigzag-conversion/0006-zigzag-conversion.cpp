class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        int index = 0;
        bool isDown = false;
        for(int i=0;i<s.size();i++){
            v[index].push_back(s[i]);
            if(isDown) {
                index--;
            }else{
                index++;
            }
            if(index == numRows - 1){
                isDown = true;
            }else if(index == 0){
                isDown = false;
            }
        }
        string res = "";
        for(int i=0;i<numRows;i++){
            res += v[i];
        }
        return res;
    }
};