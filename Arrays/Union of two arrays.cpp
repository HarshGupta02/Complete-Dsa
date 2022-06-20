class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        bitset<1000005>v;  /// works faster and highly memory efficient.
        // unordered_map<int,int>mp;
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            if(!v[a[i]]){
                cnt ++; v[a[i]] = !v[a[i]];
            }
        }
        for(int i = 0; i < m; i ++){
            if(!v[b[i]]){
                cnt ++; v[b[i]] = !v[b[i]];
            }
        }
        return cnt;
    }
};