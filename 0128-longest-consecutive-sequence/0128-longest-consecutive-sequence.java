class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int max = 0;
        int size = set.size();
        for(int num : set){
            if (!set.contains(num - 1)) {
                int start = num;
                int count = 0;
                while(set.contains(start+1)){
                    start++;
                    count++;
                }
                max = Math.max(max, count + 1);
            }
        }
        return max;
    }
}