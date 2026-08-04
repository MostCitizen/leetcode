class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        boolean used[] = new boolean[nums.length];
        backTrack(res, nums, 0, new ArrayList<>(), used);
        return res;
    }
    private void backTrack(List<List<Integer>> res, int[] nums, int index, List<Integer> list, boolean[] used){
        if(nums.length == list.size()){
            res.add(new ArrayList<>(list));
            return;
        }
        else if(nums.length <= index || index < 0) return;

        for(int i=0;i<nums.length;i++){
            if(used[i]) continue;
            used[i] = true;
            list.add(nums[i]);
            backTrack(res, nums, i, list, used);
            used[i] = false;
            list.remove(list.size() - 1);
        }
    }
}