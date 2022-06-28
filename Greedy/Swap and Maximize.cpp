using ll = long long int;
long long int maxSum(int arr[], int n)
{
    sort(arr , arr + n);
    int i = 0 , j = n - 1;
    int chance = 0; // chance = 0 means move i to right and 
    // chance = 1 means move j to left.
    ll ans = 0;
    while(i < j){
        ans += arr[j] - arr[i];
        if(chance == 0){
            i ++; chance = 1; continue;
        }
        j --; chance = 0; continue;
    }
    ans += arr[n/2] - arr[0];
    return ans;
}