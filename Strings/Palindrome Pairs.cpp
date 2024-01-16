// METHOD 1: TIME = O(N * (K ^ 2)), SPACE = O(N) => GIVES TLE

/*
here we first store the reverse of each string in a map. then for each string , we find the prefix 
and the suffix and first we check if prefix is palindrome or not . if yes then we check if the suffix
is present in map. if yes so it's reverse exist in the array so we can append it before the current
string and for a plaindrome. same we do for each suffix of the string.

*/

class Solution {
public:
    
    bool isPalindrome(string s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return (s == temp);
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        map<string,int>mp;
        for(int i = 0; i < n; i ++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mp[temp] = i;
        }
        vector<vector<int>> ans;
        if(mp.find("") != mp.end()){
            for(int i = 0; i < n; i ++){
                if(words[i].empty()) continue;
                if(isPalindrome(words[i])){
                    ans.push_back({mp[""], i});
                }
            }
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < words[i].size(); j ++){
                string prefix = words[i].substr(0, j);
                string suffix = words[i].substr(j);
                if(isPalindrome(prefix) and mp.count(suffix) and mp[suffix] != i){
                    vector<int>curr; curr.push_back(mp[suffix]); curr.push_back(i);
                    ans.push_back(curr);
                }
                if(isPalindrome(suffix) and mp.count(prefix) and mp[prefix] != i){
                    vector<int>curr; curr.push_back(i); curr.push_back(mp[prefix]);
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};

/*
whenever a string is palindrome then some middle portion of the string is 
palindrome and the left and right remaining portion will be reverse of each other.
*/

// METHOD 2: 