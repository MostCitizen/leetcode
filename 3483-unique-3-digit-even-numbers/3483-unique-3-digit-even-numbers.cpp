class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> s;
        for(int i=0;i<n;i++){
            if(digits[i] == 0) continue;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                for(int k=0;k<n;k++){
                    int value = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(digits[k] % 2 == 1 || s.contains(value)) continue;
                    else if(i == k || j == k) continue;
                    s.insert(value);
                }
            }
        }
        return s.size();
    }
};