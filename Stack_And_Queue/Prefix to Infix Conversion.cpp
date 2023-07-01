/*
INFIX = OPERAND OPERATOR OPERAND
PREFIX = OPERATOR OPERAND OPERAND
POSTFIX = OPERAND OPERAND OPERATOR
*/

class Solution {
  public:
    string preToInfix(string s) {
        int n = s.size();
        stack<string> stk;
        for(int i = n - 1; i >= 0; i --) {
            if(isalpha(s[i])) {
                string curr = "";
                curr.push_back(s[i]);
                stk.push(curr);
            }else {
                string s1 = stk.top(); stk.pop();
                string s2 = stk.top(); stk.pop();
                string curr = "(" + s1 + s[i] + s2 + ")" ;
                stk.push(curr);
            }
        }
        return stk.top();
    }
};