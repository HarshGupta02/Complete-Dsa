/// TIME : DOUBT ??

class Solution
{
    public:
    int mini = INT_MAX;
    int find_start(vector<int>parent , vector<int>diameter , map<int,int>mp , int end){
        mini = min(mini , diameter[end]);
        if(mp[end] != 0){
            return find_start(parent,diameter,mp,mp[end]);
        }
        return end;
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<int>parent(n + 1, -1),diameter(n + 1, INT_MAX);
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i = 0; i < p ; i ++){
            parent[a[i]] = b[i];
            mp[b[i]] = a[i];
            diameter[a[i]] = d[i];
        }
        int connected_comp = 0;
        for(int i = 1; i <= n ; i ++){
            if(parent[i] == -1) connected_comp ++;
        }
        for(int i = 1; i <= n ; i ++){
            if(parent[i] == -1){
                mini = INT_MAX;
                int end = i;
                int start = find_start(parent,diameter,mp,end);
                if(start == end) continue;
                vector<int>curr = {start , end , mini};
                ans.push_back(curr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};