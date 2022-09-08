/*

Divide and Conquer :

here we first count the freq of each char in the whole string. then if we find a character with 
freq < k so it cannot be part of any substring so either the substring will be on its left or on
it's right so we recursively call for both left and right substrings.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n == 0 or n < k) return 0;
        if(k <= 1) return n;
        unordered_map<char,int>mp;
        for(auto ch : s) mp[ch] ++;
        int left = 0;
        while(left < n and mp[s[left]] >= k) left ++;
        if(left >= n - 1) return left;
        int a = longestSubstring(s.substr(0, left), k);
        while(left < n and mp[s[left]] < k) left ++;
        int b = longestSubstring(s.substr(left), k);
        return max(a, b);
    }
};