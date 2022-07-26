class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        set<int>st;
        for(int i = n - 1; i >= 0 ; i --){
            st.insert(arr[i]);
            auto it = st.upper_bound(arr[i]);
            if(it != st.end()) arr[i] = *it;
            else arr[i] = -1;
        }
        return arr;
    }
};