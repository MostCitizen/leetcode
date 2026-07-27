class Solution {
  List<List<int>> generate(int numRows) {
    List<List<int>> list = [
        [1]
    ];
    for(int i=1;i<numRows;i++){
        list.add(List.filled(i + 1, 1));
        for(int j=1;j<i;j++){
            list[i][j] = list[i-1][j-1] + list[i-1][j];
        }
    }
    return list;
  }
}