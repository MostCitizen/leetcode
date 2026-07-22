class Solution {
    List<String> letter = [
        "", "", "abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    ];
  List<String> letterCombinations(String digits) {
    List<String> res = [];
    for(var i=0;i<letter[int.parse(digits[0])].length;i++){
        res.add(letter[int.parse(digits[0])][i]);
    }
    for(var i=1;i<digits.length;i++){
        final size = res.length;
        List<String> temp = [];
        for(var j=0;j<size;j++){
            for(var k=0;k<letter[int.parse(digits[i])].length;k++){
                temp.add(res[j] + letter[int.parse(digits[i])][k]);
            }
        }
        res = temp;
    }
    return res;
  }
}