class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> temp(numRows);
        int index=0;
        bool flag = false;
        for(int i=0;i<s.size();i++){
            if(index == numRows-1){
                flag = true;
            }
            else if(index == 0){
                flag = false;
            }
            temp[index] += s[i];
            index = flag ? (index - 1) : (index + 1);
        }
        string result = "";
        for(int i=0;i<numRows;i++){
            result+= temp[i];
        }

        return result;
    }
};