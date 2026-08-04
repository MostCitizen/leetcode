class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backTrack(res, nums, 0, new ArrayList<>());
        return res;  
    }

    private void backTrack(List<List<Integer>> res, int[] nums, int index, List<Integer> list){
        if(index == nums.length){
            res.add(new ArrayList<>(list));
            return;
        }
        else if(index > nums.length) return;
        list.add(nums[index]);
        backTrack(res, nums, index+1, list);
        list.remove(list.size()-1);
        backTrack(res, nums, index+1, list);
    }
}