// TIME = O(N * (N ^ M))

/*
here we color all the nodes sequence wise and for each node , we try all possible colors
*/

class Solution{
public:
    // here it is assumed that the graph is connected
    
    bool isSafe(int curr_node, int n, int m, bool graph[101][101], vector<int> &color, int curr_color){
        for(int i = 0; i < n ; i ++){
            if(curr_node != i and graph[curr_node][i] == 1 and color[i] == curr_color) return false;
        }
        return true;
    }
    
    bool f(int curr_node, int n, int m, bool graph[101][101], vector<int> &color){
        if(curr_node == n) return true;
        for(int i = 1; i <= m; i ++){
            if(isSafe(curr_node, n, m, graph, color, i)){
                color[curr_node] = i;
                if(f(curr_node + 1, n, m, graph, color)) return true;
                color[curr_node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n, 0);
        int curr_node = 0;
        return f(curr_node, n, m, graph, color);
    }
};