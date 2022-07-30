vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    map<int,int>mp;
    for(int i = 0; i < n ; i ++){
        for(int j = 0; j < m ; j ++){
            if(mp[mat[i][j]] != i) continue;
            mp[mat[i][j]] ++;
            if(mp[mat[i][j]] > (i + 1)) mp[mat[i][j]] = i + 1;
        }
    }
    vector<int>ans;
    for(auto it : mp){
        if(it.second == n) ans.push_back(it.first);
    }
    return ans;
}