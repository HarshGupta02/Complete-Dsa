/*
here we see that the cost of reversal of one edge is 1 and for not reversing is 0. so we just add
an edge of weight 1 btw all the existing relations of the node.
*/

#include<bits/stdc++.h>
using namespace std;

int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
    vector<vector<pair<int,int>>>v(n);
    for(int i = 0 ; i < n ; i ++){
        for(auto neigh : edgeList[i]){
            v[i].push_back({neigh,0});
            v[neigh].push_back({i,1});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,start});
    vector<int>dist(n,INT_MAX);
    dist[start] = 0;
    while(!pq.empty()){
        int curr_node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        for(auto neigh : v[curr_node]){
            int neigh_node = neigh.first;
            int neigh_dist = neigh.second;
            if(dist[curr_node] + neigh_dist < dist[neigh_node]){
                dist[neigh_node] = dist[curr_node] + neigh_dist;
                pq.push({dist[neigh_node],neigh_node});
            }
        }
    }
    return dist[end];
}