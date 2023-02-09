/*
TIME = O(26 * 26 * N)

so here we store all the suffixies that start with the same character and then since
characters are just 26 so we iterate over all pairs of characters i and j and find
those suffix that occur in both the groups and then find distinct suffix in each 
group and multiply them.

*/

class Solution {
public:
    using ll = long long int;
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        unordered_map<char, unordered_set<string>> mp;
        for(int i = 0; i < n; i ++){
            mp[ideas[i][0]].insert(ideas[i].substr(1));
        }
        ll res = 0;
        for(char ch1 = 'a'; ch1 <= 'z'; ch1 ++){
            for(char ch2 = 'a'; ch2 <= 'z'; ch2 ++){
                if(ch1 == ch2) continue;
                int common = 0;
                for(auto suffix : mp[ch1]){
                    if(mp[ch2].find(suffix) != mp[ch2].end()) common ++;
                }
                int n1 = mp[ch1].size() - common, n2 = mp[ch2].size() - common;
                res += (n1 * n2);
            }
        }
        return res;
    }
};