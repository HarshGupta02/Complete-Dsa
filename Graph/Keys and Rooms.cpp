class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>q;
        q.push(0);
        vector<bool>seen(n, false);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            seen[curr] = true;
            for(auto neigh : rooms[curr]){
                if(!seen[neigh]) q.push(neigh);
            }
        }
        for(auto it : seen) if(it == false) return false;
        return true;
    }
};