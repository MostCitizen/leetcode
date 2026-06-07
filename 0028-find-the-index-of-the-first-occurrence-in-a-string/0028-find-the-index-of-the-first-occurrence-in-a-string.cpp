class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;
        int needleSize = needle.size();
        int index = 0;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i] == needle[index]){
                index++;
            }
            else {
                i = i - index;
                index = 0;
            }
            if(index == needleSize){
                result = i+1 - index;
                break;
            }
        }
        return result;
    }
};