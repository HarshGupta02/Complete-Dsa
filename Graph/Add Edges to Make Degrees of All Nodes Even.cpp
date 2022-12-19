/*
1. acc to handshake theorum, the number of odd degrees nodes are always even.
2. so acc to ques, there can always be 2 or 4 number of degree nodes.
3. if odd_degree_cnt = 2 then we first check if there exists an edge that directly
connect them or not. if not, so true else check if we can make use of a third node
as intermediate node such that both new edges do not exist already as the degree of
the third node willl remain even.
4. if odd_degree_cnt = 4 so we try to connect each node with every other three and 
check if both pair of edges exist or not. if not so true else false;
*/

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> degree(n + 1, 0);
        map<pair<int,int>,int>mp;
        for(int i = 0; i < m; i ++){
            int u = edges[i][0], v = edges[i][1];
            degree[u] ++;
            degree[v] ++;
            mp[{u,v}] = 1; mp[{v,u}] = 1;
        }
        vector<int> odd;
        for(int i = 1; i <= n; i ++){
            if(degree[i] % 2 == 1) odd.push_back(i);
        }
        if(odd.size() % 2 == 1 or odd.size() > 4) return false;
        if(odd.size() == 0) return true;
        if(odd.size() == 2){
            int fst = odd[0], snd = odd[1];
            if(mp[{fst,snd}] == 0) return true;
            for(int i = 1; i <= n; i ++){
                if(mp[{fst,i}] == 0 and mp[{snd, i}] == 0) return true;
            }
            return false;
        }else{
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            if(mp[{a,b}] == 0 and mp[{c,d}] == 0) return true;
            if(mp[{a,c}] == 0 and mp[{b,d}] == 0) return true;
            if(mp[{a,d}] == 0 and mp[{b,c}] == 0) return true;
            return false;
        }
    }
}; 