class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rSize = ransomNote.size(), mSize = magazine.size();
        if(rSize > mSize) return false;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int index = 0;
        for(int i=0;i<mSize;i++){
            if(ransomNote[index] == magazine[i]){
                index++;
            }
            if(index == rSize) break;;
        }

        return index == rSize;
    }
};