// METHOD 1:

class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        set<int>st;
        int max = -1, ans = 0;
        for(int i = 0; i < n; i ++){
            st.insert(a[i]);
            while(st.count(max + 1)) max ++;
            if(max == i) ans ++;
        }
        return ans;
    }
};

// METHOD 2:

class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        int nax = -1, ans = 0;
        for(int i = 0; i < n; i ++){
            nax = max(nax, a[i]);
            if(nax == i) ans ++;
        }
        return ans;
    }
};