// METHOD 1: TIME = O(K * LOG N), SPACE = O(N * N + K).

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    using Node = pair<int,pair<int,int>>;
    priority_queue<Node,vector<Node>,greater<Node>>pq;
    pq.push({mat[0][0],{0,0}});
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    visited[0][0] = true;
    int curr = 0;
    while(curr != (k - 1)){
        Node temp = pq.top();
        pq.pop();
        int curr_x = temp.second.first ,curr_y = temp.second.second;
        if(curr_x + 1 < n and !visited[curr_x + 1][curr_y]) {
            pq.push({mat[curr_x + 1][curr_y], {curr_x + 1, curr_y}});
            visited[curr_x + 1][curr_y] = true;
        }
        if(curr_y + 1 < n and !visited[curr_x][curr_y + 1]) {
            pq.push({mat[curr_x][curr_y + 1], {curr_x, curr_y + 1}});
            visited[curr_x][curr_y + 1] = true;
        }
        curr ++;
    }
    return pq.top().first;
}

// METHOD 2: TIME = O(K * LOG N) , SPACE = O(N) - WORST CASE.

// NOT MY SOL :(

/*
here we know that the smallest element is the first element in the matrix and 
we push in queue(x,y) and then select it's 2 childs which are (x + 1,y) and 
(x, y + 1) and push them in queue and take the min of all the unopened nodes.

but we need to keep track of nodes that are visited and inserted in the queue.

so to avoid it , we insert the head of all the rows first and then just check
the (x, y + 1)th element and insert it in the queue.

*/

struct module{
    int data;
    int x;
    int y;
    module(int data, int x, int y){
        this->data=data;
        this->x=x;
        this->y=y;
    }
};

struct cmp{
    bool operator()(const module &M1, const module &M2){
        return M1.data>M2.data;
    }
}; 

int kthSmallest(int mat[MAX][MAX], int n, int k) {
     priority_queue<module,vector<module>,cmp> pq;
     for(int i=0;i<n;i++){
         pq.push(module(mat[i][0],i,0));
     }
     int res=0;
     for(int i=1;i<=k;i++){
         module curr=pq.top();
         pq.pop();
         
         res=curr.data;
         int currX=curr.x;
         int currY=curr.y;
         
         if(currY+1<n){
             pq.push(module(mat[currX][currY+1],currX,currY+1));
         }
     }
     return res;
}