int minFlips (string S)
{
    int n = S.size();
    //// either 01010101... or 10101010...
    /// if of the form 01010101
    int ans1 = 0;
    int should_be = 0;
    for(int i = 0; i < n; i++){
        if((S[i] - '0') != should_be) ans1 ++;
        should_be = !should_be;
    }
    //// if of the form 10101010.....
    int ans2 = 0;
    should_be = 1;
    for(int i = 0; i < n; i++){
        if((S[i] - '0') != should_be) ans2 ++;
        should_be = !should_be;
    }
    return min(ans1 , ans2);
}