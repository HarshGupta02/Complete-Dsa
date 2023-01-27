/*
TIME = O(N * M * M), SPACE = 

unordered_set uses hash table for implementation so most of the operations take 
O(1) time like insert, find etc.

here seen[i] = true means that if we consider the string till the ith character then
it can be made by 2 or more words. if so then we consider all j's > i and if the 
substring [j + 1 .....m] so seen[j] will also be = true.

*/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st;
        for(auto word : words) st.insert(word);
        vector<string> ans;
        for(auto word : words){
            int m = word.size();
            vector<bool> seen(m + 1, false);
            seen[0] = true;
            for(int i = 0; i < m; i ++){
                if(seen[i] == false) continue;
                string curr = "";
                for(int j = i + 1; j <= m; j ++){
                    curr.push_back(word[j - 1]);
                    if(j - i < m and st.count(curr)) seen[j] = true;
                }
                if(seen[m]){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};