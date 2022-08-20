class Solution {
  public:
  
    void rep(string &ans, int &carry, int num){
        int total = num + carry, rem = total % 10;
        ans.push_back(rem + '0'); carry = total/10;
    }
  
    string findSum(string x, string y) {
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int carry = 0;
        int i = 0, j = 0;
        string ans = "";
        while(i < x.size() and j < y.size()){
            int num1 = x[i ++] - '0', num2 = y[j ++] - '0';
            int total = num1 + num2 + carry, rem = total % 10;
            ans.push_back(rem + '0'); carry = total/10;
        }
        while(i < x.size()){
            int num = x[i ++] - '0';
            rep(ans, carry, num);
        }
        while(j < y.size()){
            int num = y[j ++] - '0';
            rep(ans, carry, num);
        }
        if(carry != 0) ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        int sz = ans.size(); i = 0;
        while(i < sz and ans[i] == '0') i ++;
        if(i == sz) return "0";
        return ans.substr(i, sz - i);
    }
};