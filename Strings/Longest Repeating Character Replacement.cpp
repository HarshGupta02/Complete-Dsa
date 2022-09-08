/*

TIME = O(26 * N), SPACE = O(26).

here we have to maximize the length of the subarray so we can think of
sliding window as we greedily keep on increasing the length of the 
subarray. and for each window, we find length of window - freq of max
char. if it comes out to be <= k so we can perform operations to make
the substring with all equal characters. so we try to make all the 
characters of a given substring equal to the char with max frequency.

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>v(26, 0);
        for(int i = 0; i < n; i ++) s[i] = tolower(s[i]);
        int left = 0, right = 0, ans = 0;
        while(left < n and right < n){
            v[s[right] - 'a'] ++;
            int nax = -1;
            for(auto it : v) nax = max(nax, it);
            int window_size = right - left + 1;
            if((window_size - nax) <= k) {
                ans = max(ans, window_size);
                right ++;
            }else{
                v[s[left] - 'a'] --;
                v[s[right] - 'a'] --;
                left ++;
            }
        }
        return ans;
    }
};