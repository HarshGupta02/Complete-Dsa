class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string a = strs.front();
        string b = strs.back();
        string ans = "";
        for(int i = 0; i < a.size(); i++){
            if(a[i] == b[i]){
                ans.push_back(a[i]);
            }else break;
        }
        return ans;
    }
};