/*
here first we try to acquire the characters until we get the number of matched characters 
equal to the number of characters in "pattern". then we check for min possible length and 
then we release a character unless the count remains equal to the size of the pattern.

*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        map<char,int>mps,mpt;
        for(char ch : t) mpt[ch] ++;
        int i = -1, j = -1;
        int ccnt = 0, dcnt = n;
        string ans = "";
        while(true){
            bool flag1 = false, flag2 = false;
            while(i < m and ccnt < dcnt){
                i ++;
                mps[s[i]] ++;
                if(mps[s[i]] <= mpt[s[i]]) ccnt ++;
                flag1 = true;
            }
            while(j < i and ccnt == dcnt){
                string curr = s.substr(j + 1, i - j);
                if(ans.empty() or curr.size() < ans.size()){
                    ans = curr;
                }
                j ++;
                mps[s[j]] --;
                if(mps[s[j]] < mpt[s[j]]) ccnt --;
                flag2 = true;
            }
            if(flag1 == false and flag2 == false) break;
        }
        return ans;
    }
};

// ALTERNATE SOLUTION

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m) return "";
        vector<int> mp1(128, 0), mp2(128, 0);
        for(char ch : t) mp2[ch] ++;
        int i = 0, j = 0, len = INT_MAX, st = -1, en = -1;
        int match_cnt = 0;
        while(i < n and j < n) {
            mp1[s[j]] ++;
            if(mp1[s[j]] <= mp2[s[j]]) match_cnt ++;
            while(match_cnt == m) {
                int sz = (j - i) + 1;
                if(sz < len) {
                    len = sz; st = i; en = j;
                }
                mp1[s[i]] --;
                if(mp1[s[i]] < mp2[s[i]]) match_cnt --;
                i ++;
            }
            j ++;
        }
        return len == INT_MAX ? "" : s.substr(st, en - st + 1);
    }
};