/// TIME = O(N) , SPACE = O(1)

/*

so here we first used the goal shifting technique and we started from back that can we reach a particular index and if
we can reach that index and from here to end of array so we update the goal to the current index.

if we gurantee that we can reach the goal then ..

we use bfs on 1d array as we need min operations so we try to jump max lengths. we calculate the max length of window that we
can jump to from our current window by calculating the farthest point from the current window and set left = right + 1 and 
right = farthest till right < n - 1 and for each new window , we increment the answer by 1 (starting from 0).

*/


class Solution{
  public:
    int minJumps(int arr[], int n){
        bool can_reach = true;
        int goal = n - 1;
        for(int i = n - 2; i >= 0 ; i--){
            if(i + arr[i] >= goal){
                goal = i; continue;
            }
        }
        if(goal != 0) return -1;
        int left = 0 , right = 0;
        int cnt = 0;
        while(right < n - 1){
            int farthest = 0;
            for(int i = left ; i <= right ; i++){
                farthest = max(farthest , i + arr[i]);
            }
            left = right + 1;
            right = farthest;
            cnt ++;
        }
        return cnt;
    }
};