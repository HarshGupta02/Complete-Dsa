class Solution {
public:
    using ll = long long int;
    
    void Mergee(int low, int mid, int high, vector<ll> &v, ll &ans, ll diff){
        int left = low, right = mid + 1;
        while(left <= mid and right <= high){
            if(v[left] <= (v[right] + diff)){
                ans += (high - right + 1);
                left ++;
            }else right ++;
        }
        vector<int> temp;
        for(int i = low; i <= high; i ++) temp.push_back(v[i]);
        sort(temp.begin(), temp.end());
        for(int i = low; i <= high; i ++) v[i] = temp[i - low];
    }
    
    void Merge_Sort(int low, int high, vector<ll>&v, ll &ans, ll diff){
        if(low < high){
            int mid = low + (high - low)/2;
            Merge_Sort(low, mid, v, ans, diff);
            Merge_Sort(mid + 1, high, v, ans, diff);
            Mergee(low, mid, high, v, ans, diff);
        }
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, ll diff) {
        int n = nums1.size();
        vector<ll>v(n);
        for(int i = 0; i < n; i ++) v[i] = nums1[i] - nums2[i];
        ll ans = 0;
        Merge_Sort(0, n - 1, v, ans, diff);
        return ans;
    }
};