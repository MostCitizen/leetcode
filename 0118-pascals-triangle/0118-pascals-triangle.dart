class Solution {
  List<List<int>> generate(int numRows) {
    List<List<int>> list = [];
    for(int i=0;i<numRows;i++){
        list.add(List.filled(i + 1, 0));
        list[i][0] = 1;
        list[i][i] = 1;
    }
    for(int i=2;i<numRows;i++){
        for(int j=1;j<i;j++){
            list[i][j] = list[i-1][j-1] + list[i-1][j];
        }
    }
    return list;
  }
}