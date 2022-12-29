class Solution{
    public:
        int count_tuples(vector<int> &v){
            int n = v.size();
            int ans = 0;
            vector<int> freq(n, 0);
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < i ; j ++){
                    if(v[i] % v[j] == 0){
                        freq[i] ++;
                        ans += freq[j];
                    }
                }
            }
            return ans;
        }
}