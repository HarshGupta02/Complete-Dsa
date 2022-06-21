class Solution{
  public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int i = 0 , j = 0;
        int mini = 1e9;
        int sum = arr[0];
        while(i < n and j < n){
            while(sum <= x and j < n){
                j ++;
                if(j < n) sum += arr[j];
                else break;
            }
            while(sum > x and i < n and i <= j and j < n){
                mini = min(mini , (j - i) + 1);
                sum -= arr[i]; i ++;
            }
        }
        return mini;
    }
};