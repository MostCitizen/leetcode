class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n) return "";
        unordered_map<char, int> map;
        for(int i=0;i<n;i++){
            map[t[i]]++;
        }
        int count = 0;
        int left = 0;
        int start = 0, end = INT_MAX;
        for(int right=0;right<m;right++){
            if(map[s[right]]-- > 0){
                count++;
            }
            if(count == n){
                while(left <= right && map[s[left]] != 0){
                    map[s[left++]]++;
                }
                if(right - left < end - start){
                    start = left;
                    end = right;
                }
                count--;
                map[s[left++]]++;
            }
        }
        return end == INT_MAX ? "" : s.substr(start, end - start + 1);
    }
};