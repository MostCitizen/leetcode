class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while(left <= right){
            int len = right - left;
            int leftHeight = height[left];
            int rightHeight = height[right];
            if(leftHeight < rightHeight){
                res = max(res, len * leftHeight);
                left++;
            }else{
                res = max(res, len * rightHeight);
                right--;
            }
        }
        return res;
    }
};