class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        int n = details.size();
        vector<vector<string>>ans;
        for(int i = 0; i < n; i ++){
            if(details[i][0] == "-") continue;
            set<string>st;
            vector<string>v;
            for(int j = 1; j < details[i].size(); j ++) st.insert(details[i][j]);
            for(int j = i + 1; j < n; j ++){
                if(details[j][0] == "-") continue;
                for(int k = 1; k < details[j].size(); k ++){
                    auto pos = st.find(details[j][k]);
                    if(pos != st.end()){
                        details[j][0] = "-";
                        for(int a = 1; a < details[j].size(); a ++){
                            st.insert(details[j][a]);
                        }
                    }
                }
            }
            v.push_back(details[i][0]);
            for(auto it : st) v.push_back(it);
            ans.push_back(v);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};