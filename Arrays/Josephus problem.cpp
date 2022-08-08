// METHOD 1: TIME = O(N), SPACE = O(N)

/*
here we try to map the remaining people with indexes from 0 ... size - 1.
*/

class Solution
{
    public:
    
    int f(int n, int k){
        if(n == 1) return 0;
        int x = f(n - 1, k);
        int y = (x + k) % n;
        return y;
    }
    
    int josephus(int n, int k)
    {
       return 1 + f(n, k);
    }
};


// METHOD 2: TIME = O(N), SPACE = O(N)

/*
here we try to find the idx of the person holding the sword and then find the index
of the person who will be killed and then erase in from the vector and we on doing
this.
*/

class Solution
{
    public:
    
    void f(int n, int k, int &idx, vector<int> &v, int &ans){
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        idx = (idx + k - 1) % v.size();
        v.erase(v.begin() + idx); // takes O(N) time in worst case but not always
        // first element to delete.
        f(n, k, idx, v, ans);
    }
    
    int josephus(int n, int k)
    {
        vector<int>v(n);
        for(int i = 0; i < n ; i ++) v[i] = i;
        int idx = 0, ans = 0;
        f(n, k, idx, v, ans);
        return 1 + ans;
    }
};