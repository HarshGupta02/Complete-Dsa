/// METHOD 1: TIME = (N ^ 3) , SPACE = O(N ^ 2).


class Solution{
public:
    const int MOD = 1003;
    int countWays(int N, string S){
        string operand = "", symbol = "";
        int n = S.size();
        for(int i = 0 ; i < n ; i ++){
            if(S[i] == '&' or S[i] == '|' or S[i] == '^') symbol.push_back(S[i]);
            else operand.push_back(S[i]);
        }
        int sz = operand.size();
        vector<vector<int>>dp_true(sz , vector<int>(sz,0));
        vector<vector<int>>dp_false(sz , vector<int>(sz,0));
        for(int gap = 0 ;gap < sz ; gap ++){
            for(int i = 0, j = gap ; j < sz ; i ++, j ++){
                if(gap == 0){
                    if(operand[i] == 'T'){
                        dp_true[i][j] = 1;
                        dp_false[i][j] = 0;
                    }else{
                        dp_true[i][j] = 0;
                        dp_false[i][j] = 1;
                    }
                    continue;
                }
                for(int par = i ; par < j ; par ++){
                    
                    int ltc = dp_true[i][par];
                    int lfc = dp_false[i][par];
                    int rtc = dp_true[par + 1][j];
                    int rfc = dp_false[par + 1][j];
                    
                    if(symbol[par] == '&'){
                        dp_true[i][j] += (ltc * rtc); dp_true[i][j] = dp_true[i][j] % MOD;
                        dp_false[i][j] += (ltc * rfc + lfc * rtc + lfc * rfc); dp_false[i][j] = dp_false[i][j] % MOD;
                    }else if(symbol[par] == '|'){
                        dp_true[i][j] += (ltc * rtc + ltc * rfc + lfc * rtc); dp_true[i][j] = dp_true[i][j] % MOD;
                        dp_false[i][j] += (lfc * rfc); dp_false[i][j] = dp_false[i][j] % MOD;
                    }else{
                        dp_true[i][j] += (ltc * rfc + lfc * rtc); dp_true[i][j] = dp_true[i][j] % MOD;
                        dp_false[i][j] += (ltc * rtc + lfc * rfc); dp_false[i][j] = dp_false[i][j] % MOD;
                    }
                }
            }
        }
        return dp_true[0][sz - 1] % MOD;
    }
};