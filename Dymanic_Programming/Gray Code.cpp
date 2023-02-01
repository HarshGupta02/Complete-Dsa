/*
here to find the gray code of n bit, we use the gray code of n - 1 bit
as it will also follow the same propery and for each sequence, we will
first add 0's in front of sequence and then add 1's in front of sequence
from the back and so hamming distance btw adjacent strings will always
be 1. base case is for n = 1 {0, 1} hamming distance = 1.

*/

class Solution {
public:
    
    using ll = long long int;
    
    int btd(string s){
        ll a = 1, res = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i --){
            if(s[i] == '1') res += a;
            a = 2 * a;
        }
        return res;
    }
    
    vector<string> gen(int n){
        if(n == 1) return {"0", "1"};
        vector<string> ans;
        vector<string> temp = gen(n - 1);
        int nn = temp.size();
        for(int i = 0; i < nn; i ++) ans.push_back("0" + temp[i]);
        for(int i = nn - 1; i >= 0; i --) ans.push_back("1" + temp[i]);
        return ans;
    }
    
    vector<int> grayCode(int n) {
        vector<string> ans = gen(n);
        vector<int> res;
        for(int i = 0; i < ans.size(); i ++){
            res.push_back(btd(ans[i]));
        }
        return res;
    }
};