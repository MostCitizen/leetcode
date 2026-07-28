class Solution {
  int lengthOfLIS(List<int> nums) {
    int count = 0;
    List<int> list = [];
    for(int i=0;i<nums.length;i++){
        if(list.length == 0 || list.last < nums[i]){
            list.add(nums[i]);
        }else {
            int index = findIndex(list, nums[i]);
            list[index] = nums[i];
        }
    }
    return list.length;
  }
  int findIndex(List<int> list, int target){
    int left = 0, right = list.length-1;
    while(left <= right){
        int mid = (right+left) ~/ 2;
        if(list[mid] == target){
            return mid;
        } else if(list[mid] < target){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return left;
  }
}