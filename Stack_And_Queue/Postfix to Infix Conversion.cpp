class Solution {
  public:
    string postToInfix(string s) {
        int n = s.size();
        stack<string> stk;
        for(int i = 0; i < n; i ++) {
            if(isalpha(s[i])) {
                string curr = "";
                curr.push_back(s[i]);
                stk.push(curr);
            }else {
                string s2 = stk.top(); stk.pop();
                string s1 = stk.top(); stk.pop();
                stk.push("(" + s1 + s[i] + s2 + ")");
            }
        }
        return stk.top();
    }
};