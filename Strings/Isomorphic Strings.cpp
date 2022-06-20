class Solution
{
    public:
    bool areIsomorphic(string str1, string str2)
    {
        int n1 = str1.size() , n2 = str2.size();
        if(n1 != n2) return false;
        vector<int>v(26,-1);
        vector<bool>visited(26,false);
        for(int i = 0; i < n1 ; i ++){
            if(v[str1[i] - 'a'] == -1 and !visited[str2[i] - 'a']){
                v[str1[i] - 'a'] = (str2[i] - 'a');
                visited[str2[i] - 'a'] = true;
            }else{
                if(v[str1[i] - 'a'] != (str2[i] - 'a'))
                    return false;
            }
        }
        return true;
    }
};