class Solution {
    public boolean isSubsequence(String s, String t) {
        int sSize = s.length();
        int tSize = t.length();
        if(sSize > tSize) return false;
        int index = 0;
        for(int i=0;i<t.length();i++){
            if(index == sSize) break;
            if(t.charAt(i) == s.charAt(index)){
                index++;
            }
        }
        return index == sSize;
    }
}