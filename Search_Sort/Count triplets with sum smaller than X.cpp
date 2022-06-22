class Solution{
	using ll = long long int;
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr , arr + n);
	    ll cnt = 0;
	    for(int i = 0; i < n ; i++){
	        int j = i + 1, k = n - 1;
	        while(j < k){
	            ll curr_sum = arr[i] + arr[j] + arr[k];
	            if(curr_sum >= sum){
	                k --; continue;
	            }
	            cnt += (k - j);
	            j ++;
	        }
	    }
	    return cnt;
	}
};