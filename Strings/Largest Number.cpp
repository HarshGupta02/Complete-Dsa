/*
just like we sort an array of numbers, we will sort the array of strings and while
comparing 2 strings a and b we find a + b and b + a. if second is bigger string 
then we swap else we don't.

*/

class Solution {
public:
    
    static bool cmp(const string &a, const string &b){
        return (a + b) > (b + a);
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto it : nums) v.push_back(to_string(it));
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        for(auto it : v) ans += it;
        int i = 0;
        int sz = ans.size();
        while(i < sz and ans[i] == '0') i ++;
        if(i == sz) return "0";
        return ans.substr(i, sz);
    }
};

/*

ans = 9534330

3,30,34,5,9

1. first look for the max value of the leftmost bit among all numbers.
2. reverse all the numbers


=> 3, 03, 43, 5, 9

=> first look for units place =>

3,03,43,5 => 3,03,43 => 3, 0, 4 => 3, 0 => 0


*/