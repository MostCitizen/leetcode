class Solution {
    public int[] twoSum(int[] nums, int target) {
        List<Integer> list = Arrays.stream(nums).boxed().toList();
        for(int i=0;i<nums.length;i++){
            int num = target - nums[i];
            int index = list.lastIndexOf(num);
            if(index > i){
                return new int[] {i, index};
            }
        }

        return new int[] {-1, -1};
    }
}