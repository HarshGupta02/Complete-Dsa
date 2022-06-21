class Solution{
public:
    using ll = long long int;
	long long maxProduct(vector<int> arr, int n) {
	    ll maxi = 1, mini = 1;
	    ll glob_max = INT_MIN;
	    for(int i = 0; i < n ;i ++){
	        if(arr[i] < 0) swap(maxi , mini);
	        maxi = max((ll)arr[i] , maxi * arr[i]);
	        mini = min((ll)arr[i] , mini * arr[i]);
	        glob_max = max(glob_max , maxi);
	    }
	    return glob_max;
	}
};