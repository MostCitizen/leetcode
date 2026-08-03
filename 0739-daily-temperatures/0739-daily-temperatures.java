class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int size = temperatures.length;
        Stack<Integer> st = new Stack<Integer>();
        int[] res = new int[size];
        for(int i=0;i<size;i++){
            while(!st.isEmpty() && temperatures[st.peek()] < temperatures[i]){
                res[st.peek()] = i - st.peek();
                st.pop();
            }
            st.add(i);
        }
        return res;
    }
}