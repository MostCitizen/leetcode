class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        int size = s.length();
        String[] arr = new String[numRows];
        Arrays.fill(arr, "");
        int index = 0;
        boolean isUp = false;
        for(int i=0;i<size;i++){
            if(index == numRows-1 || index == 0){
                isUp = !isUp;
            }
            arr[index] += s.charAt(i);
            index += (isUp ? 1 : -1);
        }
        return String.join("", arr);
    }
}