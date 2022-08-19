class Solution {
public:
    
    vector<vector<char>>v;
    
    void precompute(){
        v.resize(10);
        char ch = 'a';
        for(int i = 2; i <= 9; i ++){
            if(i == 7 or i == 9){
                v[i].push_back(ch); v[i].push_back(ch + 1); 
                v[i].push_back(ch + 2); v[i].push_back(ch + 3);
                ch += 4;
            }else{
                v[i].push_back(ch); v[i].push_back(ch + 1); 
                v[i].push_back(ch + 2);
                ch += 3;
            }
        }
    }
    
    void f(int i, int n, string digits, string &temp, vector<string> &ans){
        if(i == n){
            ans.push_back(temp); return;
        }
        for(auto ch : v[digits[i] - '0']){
            temp.push_back(ch);
            f(i + 1, n, digits, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        precompute();
        int n = digits.size();
        vector<string>ans;
        if(n == 0) return ans;
        int i = 0;
        string temp = "";
        f(i, n, digits, temp, ans);
        return ans;
    }
};

/*

"23"

2 -> a
3 -> 


*/