class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> temp;
        while(x){
            temp.push_back(x%10);
            x = x/10;
        }
        int left = 0, right = temp.size()-1;
        while(left < right){
            int leftV = temp[left++];
            int rightV = temp[right--];
            if(leftV != rightV) return false;
        }
        return true;
    }
};