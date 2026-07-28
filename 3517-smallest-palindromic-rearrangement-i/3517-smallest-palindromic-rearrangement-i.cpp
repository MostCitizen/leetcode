class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        string sub = s.substr(0, size/2);
        sort(sub.begin(), sub.end());
        string rever = sub;
        reverse(rever.begin(), rever.end());
        return size % 2 == 1 ? sub + s[size/2] + rever : sub + rever;
    }
};