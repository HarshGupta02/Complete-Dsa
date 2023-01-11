class Solution {
  public:
    using ll = long long int;
    long long int minIncrements(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        int op = 0;
        for(int i = 1; i < n; i ++){
            if(arr[i] <= arr[i - 1]){
                op += (arr[i - 1] - arr[i] + 1);
                arr[i] = arr[i - 1] + 1;
            }
        }
        return op;
    }
};