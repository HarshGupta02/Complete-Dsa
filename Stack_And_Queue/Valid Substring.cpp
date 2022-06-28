/// if form a valid parenthesis so remove it else always add the bad characters to the stack
/// and take the diff btw then which gives length of valid parenthesis.

class Solution {
  public:
    int findMaxLen(string s) {
        stack<int>stk;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(stk.empty() or s[i] == '('){
                stk.push(i); continue;
            }
            if(s[stk.top()] == '('){
                stk.pop(); continue;
            }
            stk.push(i);
        }
        // now the stack contains all the elements that were bad and prevented
        // formation of longest valid substring.
        if(stk.empty()) return n;
        int prev = n , nax = -1;
        while(!stk.empty()){
            nax = max(nax , prev - stk.top() - 1);
            prev = stk.top();
            stk.pop();
        }
        return max(nax,prev);
        return -1;
    }
};