class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        bool isMin = false;
        bool isMax = false;

        while(left<=right){
            int mid = left + (right - left)/2;
            long long sqrt = (long long)mid * mid;
            if(sqrt < x){
                left = mid+1;
            }
            else if(sqrt == x){
                return mid;
            }
            else {
                right = mid-1;
            }
        }
        return right;

    }
};