class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int nums[] = Arrays.copyOf(nums1, m);
        int idx1=0,idx2=0;
        for(int i=0;i< m + n;i++){
            if(idx1 == m){
                nums1[i] = nums2[idx2++];
            }else if(idx2 == n){
                nums1[i] = nums[idx1++];
            }else{
                nums1[i] = nums[idx1] < nums2[idx2] ? nums[idx1++] : nums2[idx2++];
            }
        }
    }
}