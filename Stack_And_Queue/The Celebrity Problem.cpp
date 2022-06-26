// TIME = O(N) , SPACE = O(N)

// if both x and y know each other or both don't know each other , then both can't 
// be celebrities. exactly one of them has to be 1.

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>stk;
        for(int i = 0; i < n ; i ++){
            if(stk.empty()){
                stk.push(i); continue;
            }
            int x = stk.top() , y = i;
            if(M[y][x] == 1 and M[x][y] == 1) stk.pop();
            else if(M[y][x] == 1 and M[x][y] == 0) continue;
            else if(M[y][x] == 0 and M[x][y] == 1){
                stk.pop(); stk.push(y);
            }else stk.pop();
        }
        if(stk.empty()) return -1;
        // the elements not in stack can never be a celebrity.
        // there will always be 1 or 0 element left in the stack.
        int possible = stk.top();
        for(int i =0 ; i < n ;i++){
            if(i == possible) continue;
            if(M[i][possible] == 1 and M[possible][i] == 0) continue;
            else return -1;
        }
        return possible;
    }
};

///  TIME = O(N) , SPACE = O(1).

/// THERE CANNOT BE MORE THAN 1 CELEBRITY. SO THERE WILL ONLY BE 1 CELEBRITY.

// HERE WE ASSUME THAT C = 0 IS OUR CANDIDATE AND THEN WE CHECK IN ORDER THAT IF C KNOWS SOMEBODY
// THEN IT IS SURE THAT C CANNOT BE A CANDIDATE SO C = THE PERSON WHO IS KNOWN BY C CURRENTLY.

// THEN WE AGAIN CHECK IN SEPARATE LOOP IF C CAN BE THE CELEBRITY OR NOT.

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        /// there can only be 1 celebrity.
        int c = 0;
        for(int i = 0 ;i < n ; i ++){
            if(M[c][i] == 1){ // so c can never be candidate but i can so
            // updated c with i.
                c = i;
            }
        }
        for(int i =0 ;i < n ; i ++){
            if(i == c) continue;
            if(M[c][i] == 0 and M[i][c] == 1) continue;
            return -1;
        }
        return c;
    }
};

