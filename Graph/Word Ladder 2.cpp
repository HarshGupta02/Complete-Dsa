class Solution {
public:
    void dfs(map<string,int>&dist,map<string,vector<string>> &adj,int min_dist,vector<vector<string>>&ans,vector<string> v,string start,string end){
        if(start==end){
            reverse(v.begin(),v.end());
            ans.push_back(v);
            return;
        }
        for(int i=0;i<adj[start].size();i++){
            if(dist.find(adj[start][i])!=dist.end()&&dist[adj[start][i]]==min_dist-1){
                v.push_back(adj[start][i]);
                dfs(dist,adj,min_dist-1,ans,v,adj[start][i],end);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> dist;
        map<string,vector<string>> adj;
        set<string> st(wordList.begin(),wordList.end());
        st.insert(beginWord);
        for(auto it:st){
            for(int i=0;i<it.length();i++){
                for(int c=0;c<26;c++){
                    string tmp=it;
                    tmp[i]='a'+c;
                    if(tmp!=it&&st.find(tmp)!=st.end()){
                        adj[it].push_back(tmp);
                    }
                }
            }
        }
        dist[beginWord]=0;
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        pq.push({0,beginWord});
        while(!pq.empty()){
            pair<int,string> top=pq.top();
            pq.pop();
            if(dist[top.second]<top.first)
                continue;
            for(int j=0;j<adj[top.second].size();j++){
                string u=top.second;
                string v=adj[u][j];
                if(dist.find(v)==dist.end()){
                    dist[v]=1+top.first;
                    pq.push({top.first+1,v});
                }
                else if(dist[v]>dist[u]+1){
                    dist[v]=dist[u]+1;
                    pq.push({dist[u]+1,v});
                }
            }
        }
        vector<vector<string>> ans;
        if(dist.find(endWord)==dist.end())
            return ans;
        int min_dist=dist[endWord];
        vector<string> sub;
        sub.push_back(endWord);
        dfs(dist,adj,min_dist,ans,sub,endWord,beginWord);
        return ans;
    }
};