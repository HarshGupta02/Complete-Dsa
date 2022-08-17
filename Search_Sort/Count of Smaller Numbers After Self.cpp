/*
here we used the concept of count inversions. but to do for ascending order is difficult 
so we use the inversion count in descending order of array because if a[i] > a[j] so a[i]
will be greater for all k's > j. so we add that to answer.
*/

class Solution {
public:
    
    vector<int>freq;
    
    void Merge(int n, vector<int>& nums, vector<pair<int,int>> &v, int low, int mid, int high){
        vector<pair<int,int>>temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while(i <= mid and j <= high){
            if(v[i].first <= v[j].first) temp[k ++] = v[j ++];
            else{
                freq[v[i].second] += (high - j + 1);
                temp[k ++] = v[i ++];
            }
        }
        while(i <= mid) temp[k ++] = v[i ++];
        while(j <= high) temp[k ++] = v[j ++];
        for(int i = low; i <= high; i ++) v[i] = temp[i - low];
    }
    
    void Merge_Sort(int n, vector<int>& nums, vector<pair<int,int>> &v, int low, int high){
        if(high <= low) return;
        int mid = low + (high - low)/2;
        Merge_Sort(n, nums, v, low, mid);
        Merge_Sort(n, nums, v, mid + 1, high);
        Merge(n, nums, v, low, mid, high);
    }
    
    vector<int> countSmaller(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>>v(n);
        freq.resize(n, 0);
        for(int i = 0; i < n; i ++) v[i] = {a[i], i};
        Merge_Sort(n, a, v, 0, n - 1);
        return freq;
    }
};