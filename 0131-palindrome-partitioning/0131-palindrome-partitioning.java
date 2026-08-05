class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        backTrack(res, s, 0, new ArrayList<>());
        return res;
    }

    private void backTrack(List<List<String>> res, String s, int start, List<String> list){
        if(s.length() == start){
            res.add(new ArrayList<>(list));
            return;
        }
        for(int end = start+1;end<=s.length();end++){
            String sub = s.substring(start, end);
            if(!isPalindrome(sub)) continue;
            list.add(sub);
            backTrack(res, s, end, list);
            list.remove(list.size()-1);
        }
    }

    private boolean isPalindrome(String s){
        int left = 0, right = s.length()-1;
        while(left < right){
            if(s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
}