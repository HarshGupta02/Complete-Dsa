/*
in this case, when we have 2 sorted arrays then we see left and right pointer. if arr[left]
> (2*arr[right]) then we increment right and when its not, so we add the current count to
our answer and increment left. since arrays are sorted so the ans of previous left will
also be the answer of the new left.

*/

class Solution {
public:
    using ll = long long int;
    
    void mergee(ll low, ll mid, ll high, vector<int> &arr) {
        ll n1 = (mid - low) + 1, n2 = high - mid;
        ll a[n1], b[n2];
        for(int i = 0; i < n1; i ++) a[i] = arr[low + i];
        for(int i = 0; i < n2; i ++) b[i] = arr[mid + 1 + i];
        ll i = 0, j = 0, k = low;
        while(i < n1 and j < n2) {
            if(a[i] <= b[j]) arr[k ++] = a[i ++];
            else arr[k ++] = b[j ++];
        }
        while(i < n1) arr[k ++] = a[i ++];
        while(j < n2) arr[k ++] = b[j ++];
    }
    
    ll countPairs(ll low, ll mid, ll high, vector<int> &arr) {
        ll right = mid + 1, ans = 0;
        ll n1 = (mid - low) + 1, n2 = (high - mid);
        for(int i = low; i <= mid; i ++) {
            while(right <= high and (ll)arr[i] > ((ll)2 * arr[right])) right ++;
            ans += (right - (mid + 1));
        }
        return ans;
    }
    
    int merge_sort(ll low, ll high, vector<int> &arr) {
        if(low >= high) return 0;
        ll ans = 0;
        ll mid = (low + (high - low)/2);
        ans += merge_sort(low, mid, arr);
        ans += merge_sort(mid + 1, high, arr);
        ans += countPairs(low, mid, high, arr);
        mergee(low, mid, high, arr);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(0, n - 1, nums);
    }
};