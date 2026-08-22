class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int rSize = ransomNote.length();
        int mSize = magazine.length();
        if(rSize > mSize) return false;
        int index = 0;
        char[] rArr = ransomNote.toCharArray();
        Arrays.sort(rArr);
        char[] mArr = magazine.toCharArray();
        Arrays.sort(mArr);
        for(int i=0;i<mSize;i++){
            if(index == rSize) break; 
            else if(rArr[index] == mArr[i]){
                index++;
            }
        }
        return index == rSize;
    }
}