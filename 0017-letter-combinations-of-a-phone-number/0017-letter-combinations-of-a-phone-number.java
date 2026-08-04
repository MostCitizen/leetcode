class Solution {
    String[] mapping = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> list = new ArrayList<>();
        for(char digit : digits.toCharArray()){
            String s = mapping[digit-'0'];
            List<String> temp = new ArrayList<>();
            if(list.size() == 0){
                for(char c : s.toCharArray()){
                    temp.add(c + "");
                }
            }else {
                for(int i=0;i<list.size();i++){
                    for(char c : s.toCharArray()){
                        temp.add(list.get(i) + c);
                    }
                }
            }
            list = temp;
        }
        return list;
    }
}