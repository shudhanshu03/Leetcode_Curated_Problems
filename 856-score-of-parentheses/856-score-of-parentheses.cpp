class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int cur = 0;
        for (char i : s)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
};