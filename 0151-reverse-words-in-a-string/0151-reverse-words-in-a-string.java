class Solution {
    public String reverseWords(String s) {
        String res = "";
        String temp = "";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == ' '){
                if(temp == "") continue;
                res = temp + (res == "" ? "" : " " + res);
                temp = "";
            }else{
                temp += s.charAt(i);
            }
        }
        if(temp != ""){
            res = temp + (res == "" ? "" : " " + res);
        }
        return res;
    }
}