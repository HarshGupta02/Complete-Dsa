#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numSkills, vector<int> skills) {
    int n = 0;
    int m = skills.size();
    for(int i = 0; i < m; i ++) {
        n = max(n, skills[i]);
    }
    n ++;
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    queue<int> q;
    for(int i = 1; i < m; i += 2) {
        int u = skills[i], v = skills[i - 1];
        adj[u].push_back(v);
        degree[v] ++;
    }
    if(numSkills > n) return false;
    for(int i = 0; i < n; i ++) {
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(auto neigh : adj[curr]) {
            degree[neigh] --;
            if(degree[neigh] == 0) q.push(neigh);
        }
    }
    int cnt = 0;
    for(auto it : degree) {
        if(it == 0) cnt ++;
    }
    return cnt == numSkills;
}

int main(){
    cout << canFinish(2, {1,0,0,1}) << endl; 
    cout << canFinish(3, {1,0,2,1}) << endl;
    return 0;
}