class Solution {
    public boolean isValid(String s) {
        Deque<Character> q = new ArrayDeque<>();
        for(char c : s.toCharArray()){
            if(c == '(' || c == '[' || c == '{'){
                q.push(c);
            } else {
                if(q.isEmpty()) return false;
                char prev = q.pop();
                if (c == ')' && prev != '(') return false;
                else if (c == ']' && prev != '[') return false;
                else if (c == '}' && prev != '{') return false;
            }
        }

        return q.isEmpty();
    }
}