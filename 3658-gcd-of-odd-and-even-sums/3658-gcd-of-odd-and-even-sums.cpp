class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = pow(n, 2);
        int sumEven = sumOdd + n;
        int divide = 0;
        while(sumOdd){
            divide = sumEven % sumOdd;
            sumEven = sumOdd;
            sumOdd = divide;
        }
        return sumEven;
    }
};