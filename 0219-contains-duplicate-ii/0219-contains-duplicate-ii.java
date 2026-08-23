class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            map.computeIfAbsent(nums[i], a -> new ArrayList<>()).add(i);
        }
        boolean res = false;
        for(List<Integer> list : map.values()){
            int size = list.size();
            if(size == 1) continue;
            for(int i=0;i<size-1;i++){
                if(list.get(i+1)-list.get(i) <= k) res = true;
            }
        }
        return res;
    }
}