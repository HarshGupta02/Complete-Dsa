class Solution {
  public:
    int checkRedundancy(string s) {
        int n = s.size();
        stack<char>stk;
        for(int i = 0; i < n ;i ++){
            if(stk.empty() or s[i] != ')'){
                stk.push(s[i]); continue;
            }
            int cnt = 0;
            while(!stk.empty() and stk.top() != '('){
                cnt ++;
                stk.pop();
            }
            if(cnt <= 1) return true;
            stk.pop(); // removed the '(' character.
        }
        return false;
    }
};