class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int size = strs.length;
        if(size == 1) {
            return new ArrayList<>(List.of(Arrays.asList(strs[0])));
        }
        Map<String, List<String>> mp = new HashMap();
        for(String str : strs){
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);
            mp.computeIfAbsent(sortedStr, k -> new ArrayList<>()).add(str);
        }
        return new ArrayList<>(mp.values());
    }
}