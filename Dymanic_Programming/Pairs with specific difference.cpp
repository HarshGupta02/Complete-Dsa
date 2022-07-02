class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr , arr + N);
        int goal = N - 1;
        int sum = 0;
        for(int i = N - 2 ; i >= 0; i --){
            if(arr[i] + K > arr[goal]){
                sum += (arr[i] + arr[goal]);
                goal = i - 1; i --;
            }else goal --;
        }
        return sum;
    }
};