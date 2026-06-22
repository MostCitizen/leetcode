class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int temp[26] = {0,};
        for(char c : text){
            temp[c-'a']++;
        }
        return min({temp[0], temp[1], temp['l'-'a'] >> 1, temp['o'-'a'] >> 1, temp['n'-'a']});
    }
};