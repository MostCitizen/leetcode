class Solution {
    public int lengthOfLongestSubstring(String s) {
        int count = 0;
        int max = 0;
        int start = 0;
        Map<Character, Integer> mp = new HashMap<>();
        for(int i=0;i<s.length();i++){
            if(mp.getOrDefault(s.charAt(i), 0) > 0){
                while(start < s.length() && mp.get(s.charAt(i)) > 0){
                    mp.computeIfPresent(s.charAt(start), (key, value) -> value-1); 
                    count--;
                    start++;
                }
            }
            mp.merge(s.charAt(i), 1, (oldValue, newValue) -> oldValue + newValue);
            count++;
            max = Math.max(max, count);
        }
        return max;
    }
}