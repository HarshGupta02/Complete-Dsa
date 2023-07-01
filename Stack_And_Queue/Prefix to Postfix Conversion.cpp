class Solution {
  public:
    string preToPost(string s) {
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
                stk.push(s1 + s2 + s[i]);
            }
        }
        return stk.top();
    }
};