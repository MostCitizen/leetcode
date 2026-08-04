class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();

        backTrack(res, candidates, target, 0, new ArrayList<>(), 0);
        return res;
    }

    private void backTrack(List<List<Integer>> res, int[] candidates, int target, int sum, List<Integer> list, int index){
        if(sum > target) return;
        else if(sum == target){
            res.add(new ArrayList<>(list));
            return;
        } else if(index >= candidates.length) return;
        list.add(candidates[index]);
        backTrack(res, candidates, target, sum + candidates[index], list, index);
        list.remove(list.size() - 1);
        backTrack(res, candidates, target, sum, list, index+1);

    }
}