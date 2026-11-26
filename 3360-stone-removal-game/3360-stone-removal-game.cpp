class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        bool isTrue = true;
        int stone = 10;
        while(n >= 0){
            n = n - stone;
            isTrue = !isTrue;
            stone--;
        }
        return isTrue;
    }
};