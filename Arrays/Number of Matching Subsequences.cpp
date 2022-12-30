/*

we need to iterate the string s multiple times for each word so to avoid it, we store the 
position of each character from 'a' to 'z' in a vector and for each character in each word,
we see if the correspoding index are increasing in nature or not. if yes then only increment
the count and index is searched in the corresponding character's vector using upper bound 
wrt to the prev value and the prev value keeps on get updating.

*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        map<char,vector<int>> mp;
        for(int i = 0; i < n; i ++){
            mp[s[i]].push_back(i);
        }
        int cnt = 0;
        for(int i = 0; i < words.size(); i ++){
            string curr = words[i];
            int prev = -1;
            for(int j = 0; j < curr.size(); j ++){
                auto it = upper_bound(mp[curr[j]].begin(), mp[curr[j]].end(), prev);
                if(it == mp[curr[j]].end()) break;
                prev = *it;
                if(j == curr.size() - 1) cnt ++;
            }
        }
        return cnt;
    }
};