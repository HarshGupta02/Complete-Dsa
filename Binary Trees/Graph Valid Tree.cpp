#include<bits/stdc++.h>
using namespace std;

class DSU{
    public: 
    
    int get_parent(int a,vector<int>&parent){
        return parent[a] = (parent[a] == a) ? a : get_parent(parent[a],parent);
    }
    
    void Merge_both(int a,int b,vector<int>&parent,vector<int>&rank){
        a = get_parent(a,parent);
        b = get_parent(b,parent);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
};

void dfs(int src,vector<bool>&visited,vector<vector<int>>&adj){
    visited[src] = true;
    for(auto neigh : adj[src]){
        if(!visited[neigh]) dfs(neigh,visited,adj);
    }
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    if(m != n - 1) return false;
    vector<int>parent(n),rank(n,0);
    iota(parent.begin(),parent.end(),0);
    vector<vector<int>>adj(n);
    DSU dsu;
    for(auto it : edges){
        int u = it[0] , v = it[1];
        int p1 = dsu.get_parent(u,parent) , p2 = dsu.get_parent(v,parent);
        if(p1 == p2) return false;
        adj[u].push_back(v); adj[v].push_back(u);
        dsu.Merge_both(u,v,parent,rank);
    }
    vector<bool>visited(n,false);
    dfs(0,visited,adj);
    for(int i = 0; i < n ; i ++) if(!visited[i]) return false;
    return true;
}