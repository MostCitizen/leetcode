class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int size = nums.length;
        int subCount = size - k + 1;
        int res[] = new int[subCount];
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (nums[b] - nums[a]));

        for(int i=0;i<size;i++){
            while(!pq.isEmpty() && pq.peek() < i-k+1){
                pq.remove();
            }
            pq.add(i);
            if(i-k+1 >= 0){
                res[i-k+1] = nums[pq.peek()];
            }
        }
        return res;
    }
}