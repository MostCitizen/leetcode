class Solution {
    public String longestCommonPrefix(String[] strs) {
        int len = strs[0].length();
        if(len == 0) return "";
        int index = 0;
        boolean isD = false;
        String res = "";
        while(index < len){
            for(int i=0;i<strs.length-1;i++){
                if(index >= strs[i].length() || index >= strs[i+1].length() ||
                   strs[i].charAt(index) != strs[i+1].charAt(index)){
                    isD = true;
                    break;
                }
            }
            if(isD) break;
            res += strs[0].charAt(index++); 
        }
        return res;
    }
}