string isSubset(int a1[], int a2[], int n, int m) {
    if(m > n) return "No";
    unordered_map<int,int>bst;
    for(int i = 0; i < n ; i ++){
        bst[a1[i]] ++;
    }
    for(int i = 0; i < m ; i++){
        bst[a2[i]] --;
        if(bst[a2[i]] < 0) return "No";
    }
    return "Yes";
}