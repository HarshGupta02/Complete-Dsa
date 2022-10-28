// METHOD 1: TIME = O(N * M * LOG M), SPACE = O(N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < n; i ++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto it : mp){
            vector<string> curr = it.second;
            ans.push_back(curr);
        }
        return ans;
    }
};

/* METHOD 2: TIME : O(N * 26 * M)
here we sort a string of lowercase english letters using counting sort as 
we store the freq of each characters and then keep on appending the char and
its freq to a new string and the order in which we process these characters
will be automatically in the sorted order as we created a vector of size 26
so order ensured.
*/

class Solution {
public:
    
    string count_sort(string s){
        vector<int>f(26, 0);
        for(int i = 0; i < s.size(); i ++) f[s[i] - 'a'] ++;
        string t = "";
        for(int i = 0; i < 26; i ++){
            t += string(f[i], i + 'a');
        }
        return t;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < n; i ++){
            mp[count_sort(strs[i])].push_back(strs[i]);
        }
        for(auto it : mp){
            vector<string> curr = it.second;
            ans.push_back(curr);
        }
        return ans;
    }
};