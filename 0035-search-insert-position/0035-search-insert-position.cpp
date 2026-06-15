class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0, right=nums.size()-1;
        while(left <= right){
            int leftV = nums[left];
            int rightV = nums[right];
            if(leftV < target && rightV > target){
                left++;
                right--;
                if(left > right) return left;
            }
            else if(rightV <= target) return right + (rightV == target ? 0 :1);
            else if(leftV >= target) return left;
        }
        return -1;
    }
};