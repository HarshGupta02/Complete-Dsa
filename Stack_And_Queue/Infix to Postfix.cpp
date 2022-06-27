class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int precedence(char c){
        if(c == '^') return 3;
        if(c == '*' or c == '/') return 2;
        if(c == '+' or c == '-') return 1;
        return -1;
    }
    
    bool isOperand(char c){
        return ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'));
    }
    
    
    string infixToPostfix(string s) {
        stack<char>stk;
        string res = "";
        int n = s.size();
        for(int i = 0; i < n ; i ++){
            char c = s[i];
            if(c == '('){
                stk.push(c); continue;
            }
            if(isOperand(c)){
                res += c; continue;
            }
            if(c == ')'){
                while(stk.top() != '('){
                    res += stk.top();
                    stk.pop();
                }
                stk.pop(); continue;
            }
            while(!stk.empty() and precedence(c) <= precedence(stk.top())){
                if(c == '^' and stk.top() == '^') break;
                res += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};