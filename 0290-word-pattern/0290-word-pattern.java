class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character, String> map = new HashMap<>();
        int index = 0;
        for(int i=0;i<pattern.length();i++){
            String temp = "";
            if(index >= s.length()) return false;
            while(index < s.length() && s.charAt(index) != ' '){
                temp += s.charAt(index++);
            }
            index++;
            if(map.containsKey(pattern.charAt(i))){
                if(!map.get(pattern.charAt(i)).equals(temp)) return false;
            }else {
                if(map.containsValue(temp)) return false;
                map.put(pattern.charAt(i), temp);
            }
        }
        return index > s.length();
    }
}