class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int a[] = new int[26], b[] = new int[26];
        int pSize = p.length();
        for(int i=0;i<pSize;i++){
            b[p.charAt(i)-'a']++;
        }
        int start = 0;
        for(int i=0;i<s.length();i++){
            if(i >= pSize) a[s.charAt(start++)-'a']--;
            a[s.charAt(i)-'a']++;
            if(Arrays.equals(a, b)) res.add(start);
        }
        return res;
    }
}