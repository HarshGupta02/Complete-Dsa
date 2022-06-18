class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>mp;
        for(int i = 0; i < n; i++){
            string curr = arr[i];
            mp[curr] ++;
        }
        int nax = -1;
        for(auto it : mp)
            nax = max(nax , it.second);
        string second_best_str;
        int diff = (int)INT_MAX;
        for(auto it : mp){
            if(it.second == nax) continue;
            if(nax - it.second < diff){
                diff = nax - it.second;
                second_best_str = it.first;
            }
        }
        return second_best_str;
    }
};