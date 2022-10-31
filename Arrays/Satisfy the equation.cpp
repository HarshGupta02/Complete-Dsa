/*
so we try all possible pairs in O(n^2) and store their sum with the indexes that make
up that sum. if sum not present so insert it. if sum already present, then check if 
both the pairs are all distinct and if they are then check for lexographically smallest
vector of all 4 indices.
*/

class Solution {
  public:
    vector<int> satisfyEqn(int a[], int n) {
        map<int,pair<int,int>>mp; // mp[sum] = {i,j} the sum is made of a[i] + a[j].
        vector<int>ans(4, INT_MAX);
        for(int i = 0; i < n - 1; i ++){
            for(int j = i + 1; j < n; j ++){
                int sum = a[i] + a[j];
                if(!mp.count(sum)) mp[sum] = {i,j}; // first time the sum appears gurantees the lexographically smallest pair of indexes.
                else{
                    pair<int,int>used = mp[sum];
                    if(used.first != i and used.first != j and used.second != j and used.second != i){
                        vector<int> temp = {used.first, used.second, i, j};
                        if(ans[0] == INT_MAX){
                            for(int i = 0; i < 4; i ++) ans[i] = temp[i];
                        }
                        else{
                            bool is = false;
                            for(int i = 0; i < 4; i ++){
                                if(temp[i] < ans[i]){
                                    is = true;
                                    break;
                                }else if(ans[i] < temp[i]) break;
                            }
                            if(is){
                                for(int i = 0; i < 4; i ++) ans[i] = temp[i];
                            }
                        }
                    }
                }
            }
        }
        if(ans[0] == INT_MAX){
            for(int i = 0; i < 4; i ++) ans[i] = -1;
        }
        return ans;
    }
};