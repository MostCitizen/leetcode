class Solution {
  List<List<String>> groupAnagrams(List<String> strs) {
    Map<int, String> map = {};
    int size = strs.length;

    for(int i=0;i<size;i++){
        map[i] = (strs[i].split('')..sort()).join('');
    }
    List<List<String>> res = [];
    List<String> temp = [];
    for(int i=0;i<size;i++){
        var str = (strs[i].split('')..sort()).join('');
        if(map.containsValue(str)){
            var indexList = map.entries
                .where((entry) => entry.value == str)
                .map((entry) => entry.key)
                .toList();
            for(int index in indexList){
                temp.add(strs[index]);
                map.remove(index);
            }
            res.add(List.of(temp));
            temp = [];
        }
    }
    return res;
  }
}