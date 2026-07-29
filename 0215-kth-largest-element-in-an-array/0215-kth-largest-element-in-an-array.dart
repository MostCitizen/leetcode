import 'package:collection/collection.dart';
class Solution {
  int findKthLargest(List<int> nums, int k) {
    PriorityQueue<int> pq = PriorityQueue<int>();
    for(int i=0;i<nums.length;i++){
        pq.add(nums[i]);
    }
    for(int i=0;i<nums.length-k;i++){
        pq.removeFirst();
    }
    return pq.removeFirst();
  }
}