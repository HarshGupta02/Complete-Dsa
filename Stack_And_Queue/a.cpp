class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int>mat;
        int t=0;
        for(auto x:s)   
        {
            t=t^(1<<(x-'a'));
            mat.push_back(t);
        }
        vector<bool>res;
        for(auto x:queries)
        {
            t=mat[x[1]];
            if(x[0]>0)
                t=t^(mat[x[0]-1]);
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(((1<<i)&t)!=0)
                    cnt++;
            }
            if((cnt/2)<=x[2])
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};


vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int mask = 0;
    vector<int> ps(1);
    for (char c : s)
        ps.push_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto &q : queries) {
        int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.push_back(q[2] >= odds / 2);
    }
    return r;
}