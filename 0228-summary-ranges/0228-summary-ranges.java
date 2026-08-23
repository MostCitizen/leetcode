class Solution {
    public List<String> summaryRanges(int[] nums) {
        if(nums.length == 0) return new ArrayList<>();
        List<String> res = new ArrayList<>();
        int start = 0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i] + 1 != nums[i+1]){
                if(start == i) {
                    res.add(String.format("%d", nums[start]));
                }else {
                    res.add(String.format("%d->%d", nums[start],nums[i]));
                }
                start = i+1;
            }
        }
        if(start != nums.length-1){
            res.add(String.format("%d->%d", nums[start],nums[nums.length-1]));
        }else {
            res.add(String.format("%d", nums[start]));
        }
        return res;
    }
}