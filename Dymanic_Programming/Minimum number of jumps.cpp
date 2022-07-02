class Solution{
  public:
    int minJumps(int arr[], int n){
        int goal = n - 1;
        for(int i = n - 2; i >= 0 ; i --){
            if(i + arr[i] >= goal){
                goal = i;
            }
        }
        if(goal != 0) return -1;
        int left = 0 , right = 0;
        int jumps = 0;
        while(right < n - 1){
            int farthest = 0;
            for(int i = left ; i <= right ; i ++){
                farthest = max(farthest , arr[i] + i);
            }
            left = right + 1;
            right = farthest;
            jumps ++;
        }
        return jumps;
    }
};