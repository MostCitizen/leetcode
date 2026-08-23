class Solution {
    public String simplifyPath(String path) {
        Stack<String> st = new Stack<>();
        for (String part : path.split("/")) {
            if (part.isEmpty() || part.equals(".")) {
                continue;
            }
            if (part.equals("..")) {
                if (!st.isEmpty()) {
                    st.pop();
                }
            } else {
                st.push(part);
            }
        }
        StringBuilder res = new StringBuilder();

        while (!st.isEmpty()) {
            res.insert(0, "/" + st.pop());
        }
        return res.length() == 0 ? "/" : res.toString();
    }
}