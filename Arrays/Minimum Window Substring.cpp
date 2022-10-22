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