class Solution {
    public int strStr(String haystack, String needle) {
        int needleSize = needle.length();
        for(int i=0;i<=haystack.length()-needleSize;i++){
            String temp = haystack.substring(i, i + needleSize);
            if(temp.equals(needle)) return i;
        }
        return -1;
    }
}