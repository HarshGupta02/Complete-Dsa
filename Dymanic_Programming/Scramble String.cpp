/*
if two strings do not have same freq of distinct characters then they cannot be 
scrambled strings of each other.

*/

class Solution {
public:
    unordered_map<string, bool> mp;
    bool f(string s1, string s2){
        int n = s1.size();
        if(n == 1) return (s1[0] == s2[0]);
        string used = s1 + s2;
        if(mp.find(used) != mp.end()) return mp[used];
        vector<int> f1(26, 0), f2(26, 0);
        for(int i = 0; i < n; i ++){
            f1[s1[i] - 'a'] ++;
            f2[s2[i] - 'a'] ++;
        }
        if(f1 != f2) return mp[used] = false;
        for(int i = 1; i < n; i ++){
            bool left = f(s1.substr(0, i), s2.substr(0, i)) and f(s1.substr(i), s2.substr(i));
            bool right = f(s1.substr(0, i), s2.substr(n - i)) and f(s1.substr(i), s2.substr(0, n - i));
            if(left or right) return mp[used] = true;
        }
        return mp[used] = false;
    }
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return f(s1, s2);
    }
};