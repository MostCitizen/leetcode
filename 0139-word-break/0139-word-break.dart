class Solution {
  bool wordBreak(String s, List<String> wordDict) {
    Set<String> dict = wordDict.toSet();
    for(int i=0;i<s.length;i++){
        String sub = s.substring(0, i);
        if(!dict.contains(sub)) continue;
        for(String word in wordDict){
            String newWord = sub + word;
            if(s == newWord) return true;
            dict.add(newWord);
        }
    }
    return dict.contains(s);
  }
}