class Solution{
    public:
    
    void dfs(int src, vector<vector<int>> &adj , stack<int> &stk,vector<bool> &visited){
        visited[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh , adj,stk,visited);
        }
        stk.push(src);
    }
    
    string findOrder(string dict[], int N, int K) {
        // sort(dict , dict + N , greater<string>());
        map<char,int>mp;
        map<int,char>mp1;
        int num = 1;
        for(char ch = 'a'; ch <= 'z' ; ch ++){
            mp[ch] = num; mp1[num] = ch; num ++;
        }
        vector<vector<int>>adj(27);
        for(int i = 0; i < N - 1; i ++){
            string s1 = dict[i]; string s2 = dict[i + 1];
            int st = 0 , en = 0;
            while(st < s1.size() and en < s2.size()){
                if(s1[st] != s2[en]){
                    int n1 = mp[s1[st]]; int n2 = mp[s2[en]];
                    adj[n1].push_back(n2);
                    break;
                }
                st ++; en ++;
            }
        }
        stack<int>stk; vector<bool>visited(27 , false);
        for(int i = 1; i <= 26; i ++){
            if(!visited[i])
                dfs(i,adj,stk,visited);
        }
        string ans = "";
        while(!stk.empty()){
            char ch = mp1[stk.top()];
            ans += ch;
            stk.pop();
        }
        return ans;
    }
};