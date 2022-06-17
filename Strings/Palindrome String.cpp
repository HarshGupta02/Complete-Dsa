int isPalindrome(char S[])
{
    int n = strlen(S); 
    // int n = S.size()  if c ++ strings was passed as argument
    for(int i = 0; i < n/2; i++){
        if(S[i] != S[n - i - 1]) return 0;
    }
    return 1;
}