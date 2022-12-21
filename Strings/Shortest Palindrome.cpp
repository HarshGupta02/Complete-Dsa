/*

here we first add the reverse of the given string to the original string 
separated by a "#". then for the new string, we find the lps array. so the last
element of the lps array tells that this much amount of lenght of prefix is same
as the suffix and which means that they are palindrome as if reverse of a string
is same as a string so they are palindrome.

then we add the remaining characters to the front of the string to make it
palindrome.

*/

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string temp = s;
        reverse(temp.begin(), temp.end());
        string neww = s + "#" + temp;
        int m = neww.size();
        int i = 1, len = 0;
        vector<int> lps(m, 0);
        while(i < m){
            if(neww[i] == neww[len]){
                len ++;
                lps[i] = len;
                i ++;
            }else{
                if(len > 0) len = lps[len - 1];
                else{
                    lps[i] = 0;
                    i ++;
                }
            }
        }
        int last = lps.back();
        string t = s.substr(last);
        reverse(t.begin(), t.end());
        return t + s;
    }
};