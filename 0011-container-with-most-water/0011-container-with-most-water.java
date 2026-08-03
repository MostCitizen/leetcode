class Solution {
    public int maxArea(int[] height) {
        int m = 0;
        int left =0, right = height.length-1;
        while(left < right){
            m = Math.max(m, (right-left) * Math.min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return m;
    }
}