class Solution {
  int minimumPushes(String word) {
    int count = 0;
    int add = 1;
    int size = word.length;
    while(size ~/ 8 != 0){
        int temp = size ~/ 8;
        count += 8 * add++;
        size = size % 8 + (size >= 8 ? (temp - 1) * 8 : 0);
    }
    count += size % 8 * add;
    return count;
  }
}