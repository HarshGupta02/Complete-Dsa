// METHOD 1 : TIME = O(31 * N) ~ O(N) , SPACE = O(31 * N) USES COUNTING SORT

// HERE WE USE THE REVERSE APPROACH AND INSERT ELEMENTS ACC TO THEIR NUMBER OF SET BITS IN THE 
// VECTOR AND ITERATE FROM BACK AND THIS ENSURES DECREASING ORDER AS WELL AS INPLACE PROPERTY.

class Solution{
    public:
    int set_bits(int x){
        int cnt = 0;
        while(x != 0){
            if(x & 1) cnt ++;
            x >>= 1;
        }
        return cnt;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<vector<int>>v(32);
        for(int i = 0; i < n ; i ++){
            int set_bits = __builtin_popcount(arr[i]);
            v[set_bits].push_back(arr[i]);
        }
        int k = 0 ;
        for(int i = 31 ; i >= 0 ; i --){
            if(!v[i].empty()){
                for(auto it : v[i]){
                    arr[k] = it;
                    k ++;
                }
            }
        }
    }
};


/// METHOD : 2 USING STL

class Solution{
    public:
    static bool cmp(int a , int b){
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        return x > y;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr , arr + n , cmp);
    }
};

