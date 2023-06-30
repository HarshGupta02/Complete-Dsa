/*
so here we see that the characters z,w,u,x,g (0,2,4,6,8) occur in exactly one digits 
so they are unique so first we count their frequency. so if we look in remaining 
characters we see each digit and try to find the character which is unique to 
(1,3,5,7,9) and then find its frequency based on total frequency of that character
minus the used up by (0,2,4,6,8).
*/

class Solution {
public:
    string originalDigits(string s) {
        int n = s.size();
        vector<int> f(26, 0);
        for(int i = 0; i < n; i ++) f[s[i] - 'a'] ++;
        vector<int> digits(10, 0);
        digits[0] = f['z' - 'a'];
        digits[2] = f['w' - 'a'];
        digits[4] = f['u' - 'a'];
        digits[6] = f['x' - 'a'];
        digits[8] = f['g' - 'a'];
        
        digits[1] = f['o' - 'a'] - digits[0] - digits[2] - digits[4];
        digits[3] = f['t' - 'a'] - digits[2] - digits[8];
        digits[5] = f['f' - 'a'] - digits[4];
        digits[7] = f['s' - 'a'] - digits[6];
        digits[9] = f['i' - 'a'] - digits[6] - digits[8] - digits[5];
        
        string ans = "";
        for(int i = 0; i < 10; i ++) {
            while(digits[i] > 0) {
                digits[i] --;
                ans.push_back(i + '0');
            }
        }
        return ans;
    }
};