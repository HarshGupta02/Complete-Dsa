/*
here we sort attacks in decreasing order and if same attack so sort defence in 
ascending order. and we keep a max_defence from the left. so if max_defence > curr_defence
then it is a weak element because a character of same attack cannot have greater 
defence that the curr defence.
*/

class Solution {
public:
    
    static bool cmp(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), cmp);
        int max_defence = INT_MIN, cnt = 0;
        for(int i = 0; i < n; i ++){
            if(max_defence > properties[i][1]) cnt ++;
            max_defence = max(max_defence, properties[i][1]);
        }
        return cnt;
    }
};