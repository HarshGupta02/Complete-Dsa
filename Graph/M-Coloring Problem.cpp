#include<bits/stdc++.h>
using namespace std;

// let there be m colors - 0,1,2,3.....m - 1

void dfs(int src,vector<bool>&visited,vector<vector<int>> &adj,int n , int m,vector<int> &color,bool &possible){
    visited[src] = true;
    vector<bool>isColor(m,false);
    for(auto neigh : adj[src]){
        if(color[neigh] != -1) isColor[color[neigh]] = true;
    }
    int can_be_used = -1;
    for(int i = 0 ; i < m ; i ++){
        if(isColor[i] == false){
            can_be_used = i; break;
        }
    }
    if(can_be_used == -1){
        possible = false; return;
    }
    color[src] = can_be_used;
    for(auto neigh : adj[src]){
        if(!visited[neigh]) dfs(neigh,visited,adj,n,m,color,possible);
    }
}

string graphColoring(vector<vector<int>>& adjMatrix, int n, int m)
{
    vector<vector<int>>adj(n);
    for(int i = 0; i < n ; i ++){
        for(int j = 0; j < n ; j ++){
            if(adjMatrix[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
    vector<bool>visited(n,false);
    vector<int>color(n,-1);
    bool possible = true;
    for(int i = 0; i < n ; i ++){
        if(!visited[i]) dfs(i,visited,adj,n,m,color,possible);
    }
    if(possible) return "Yes";
    return "No";
}
