class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<tokens.length;i++){
            try{
                int num = Integer.parseInt(tokens[i]);
                st.add(num);
            }catch (NumberFormatException e){
                int cal = 0;
                int num2 = st.pop();
                int num1 = st.pop();
                if(tokens[i].equals("+")){
                    cal = num1 + num2;
                }else if(tokens[i].equals("-")){
                    cal = num1 - num2;
                }else if(tokens[i].equals("*")){
                    cal = num1 * num2;
                }else if(tokens[i].equals("/")){
                    cal = num1 / num2;
                }
                st.add(cal);
            }
        }
        return st.pop();
    }
}