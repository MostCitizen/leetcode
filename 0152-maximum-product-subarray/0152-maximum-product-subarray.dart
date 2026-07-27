class Solution {
  int maxProduct(List<int> nums) {
    int m = nums[0];
    int product = 1;
    for(int i=0;i<nums.length;i++){
        product *= nums[i];
        m = max(m, product);
        if(product == 0) product = 1;
    }
    product = 1;
    for(int i=nums.length-1;i>=0;i--){
        product *= nums[i];
        m = max(m, product);
        if(product == 0) product = 1;
    }
    return m;
  }
}