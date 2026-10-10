class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int arr[26] = {0, };
        int count = 0;
        for(char c : s){
            arr[c-'a']++;
            count++;
        }
        for(char c : t){
            if(arr[c-'a']-- > 0){
                count--;
            }
        }
        return count == 0;
    }
};