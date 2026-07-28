class Solution {
  String smallestPalindrome(String s) {
    int size = s.length;
    List<String> letters = s.split('');
    Map<String, int> map = Map();
    letters.sort();
    for(int i=0;i<size;i++){
        map.update(letters[i], (val) => val + 1, ifAbsent: () => 1);
    }
    int index = 0;
    if(map.containsValue(1)){
        var t = map.entries.firstWhere(
            (element) => element.value == 1,
        );
        letters[size~/2] = t.key;
        map.remove(t.key);
    }
    map.forEach((key, value) {
        if(value%2 == 1){
            letters[size~/2] = key;
        }
        for(int i=0;i<value~/2;i++){
            letters[index] = key;
            letters[size-1-index] = key;
            index++;
        }
    });
    return letters.join('');
  }
}