class Solution{
  public:
    
    vector<string>ans;
    using ll = long long int;
    
    bool isValid(string s , string& temp){
        int dot_cnt = 0;
        int n = temp.size();
        for(int i = 0; i < n; i++){
            if(temp[i] == '.') dot_cnt ++;
        }
        if(dot_cnt != 3 or (n - dot_cnt != s.size())) return false;
        int start = 0;
        for(int i = 0; i < n; i++){
            if(temp[i] == '.'){
                string curr = temp.substr(start , i - start);
                ll num = stoll(curr);
                if(num != 0 and curr[0] == '0') return false;
                if(num < 0 or num > 255) return false;
                start = i + 1;
            }
        }
        string curr = temp.substr(start , n - start);
        if(curr.size() == 1 and curr[0] == '0') return true;
        ll num = stoll(curr);
        if(num != 0 and curr[0] == '0') return false;
        if(num <= 0 or num > 255) return false;
        return true;
    }
    
    void f(int i , int n , int k , string s , string temp){
        if(i >= n or k == 0){
            if(isValid(s , temp)){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(s[i]);
        if(i == n - 1){
            f(i + 1 , n , k , s , temp);
        }else{
            temp.push_back('.'); k --;
            f(i + 1 , n , k , s , temp);
            temp.pop_back(); k ++;
            f(i + 1, n , k ,s ,temp);
        }
    }
  
    vector<string> genIp(string &s) {
        int n = s.size();
        if(n <= 3){
            ans.push_back("-1");
            return ans;
        }
        f(0,n,4,s,"");
        return ans;
    }
};