class Solution
{
    public:
    //Function to evaluate a postfix expression.
    
    bool isNum(char c){
        return (c >= '0' and c <= '9');
    }
    
    int operation(int op1 , int op2 , char c){
        if(c == '*') return op1 * op2;
        if(c == '+') return op1 + op2;
        if(c == '-') return op1 - op2;
        return op1 / op2;
    }
    
    int evaluatePostfix(string S)
    {
        stack<int>stk;
        int n = S.size();
        for(int i = 0; i < n ; i++){
            char c = S[i];
            if(isNum(c)) stk.push(c - '0');
            else{
                int op2 = stk.top(); stk.pop();
                int op1 = stk.top(); stk.pop();
                stk.push(operation(op1,op2,c));
            }
        }
        return stk.top();
    }
};