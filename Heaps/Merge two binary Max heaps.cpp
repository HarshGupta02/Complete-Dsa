// METHOD 1: TIME = O(M * LOG N)

class Solution{
    public:
    
    void heap_insert_element(vector<int> &a,int val){
        a.push_back(val);
        int curr = a.size() - 1;
        int par = ceil((double)curr/2) - 1;
        while(curr > 0 and a[par] < a[curr]){
            swap(a[par] , a[curr]);
            curr = par;
            par = ceil((double)curr/2) - 1;
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        if(n < m) return mergeHeaps(b,a,m,n);
        for(int i = 0; i < m ; i ++){
            heap_insert_element(a,b[i]);
        }
        return a;
    }
};

// METHOD 2: TIME = O(N + M)

class Solution{
    public:
    
    void max_heapify(vector<int>& c, int curr, int n){
        int l = 2 * curr + 1;
        int r = 2 * curr + 2;
        int largest;
        if(l < n and c[l] > c[curr]) largest = l;
        else largest = curr;
        if(r < n and c[r] > c[largest]) largest = r;
        if(largest != curr){
            swap(c[curr] , c[largest]);
            max_heapify(c, largest,n);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>c;
        for(int i = 0; i < n ; i ++) c.push_back(a[i]);
        for(int i = 0; i < m ; i ++) c.push_back(b[i]);
        n = c.size();
        for(int i = (n/2) - 1; i >= 0 ; i --){
            max_heapify(c,i,n);
        }
        return c;
        
    }
};