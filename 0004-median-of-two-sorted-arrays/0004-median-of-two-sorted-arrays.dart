class Solution {
  double findMedianSortedArrays(List<int> nums1, List<int> nums2) {
    List<int> list = [];
    for(int i=0;i<nums1.length;i++){
        list.add(nums1[i]);
    }
    for(int i=0;i<nums2.length;i++){
        list.add(nums2[i]);
    }
    list.sort();
    final isOdd = list.length % 2 == 1;
    if(isOdd){
        return list[list.length ~/ 2].toDouble();
    }
    else {
        return (list[list.length ~/ 2 - 1] + list[list.length ~/ 2]) / 2;
    }
  }
}