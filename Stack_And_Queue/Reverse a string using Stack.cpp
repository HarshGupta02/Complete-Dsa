char* reverse(char *S, int len)
{
    stack<char>stk;
    for(int i = 0; i < len ; i ++){
        stk.push(S[i]);
    }
    int i = 0;
    while(!stk.empty()){
        *(S + i) = stk.top();
        stk.pop();
        i ++;
    }
    return S;
}