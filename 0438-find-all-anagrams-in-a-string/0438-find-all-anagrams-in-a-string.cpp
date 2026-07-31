class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int pSize = p.size();
        int sSize = s.size();
        if(pSize > sSize) return v;
        vector<int> a(26, 0), b(26, 0);
        for(int i=0;i<pSize;i++){
            a[s[i]-'a']++;
            b[p[i]-'a']++;
        }
        int left = 0;
        for(int i=pSize;i<sSize;i++){
            if(a == b) v.push_back(left);
            a[s[left++] - 'a']--;
            a[s[i]- 'a']++;
        }
        if(a == b) v.push_back(left);
        return v;
    }
};