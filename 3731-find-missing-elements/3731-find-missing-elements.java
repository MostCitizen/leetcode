class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        Arrays.sort(nums);
        List<Integer> list = new ArrayList<>();
        int index = 0;
        for(int i=nums[0];i<nums[nums.length-1];i++){
            if(nums[index] == i) index++;
            else list.add(i);
        }
        return list;
    }
}