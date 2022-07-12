/*
here if there are n elements in an array then there are 2^n subsets possible and each 
number from 0 to 2^n - 1 is a submask in which each set bit from right tells which element
is included from the original array.
*/


class Solution{
	public:
	vector<string> AllPossibleStrings(string s){
	    int n = s.size();
	    vector<string>ans;
	    for(int mask = 0; mask < (1 << n); mask ++){
	        string curr = "";
	        for(int i = 0; i < n ; i++){
	            if((mask & (1 << i)) != 0){
	                curr += s[i];
	            }
	        }
	        if(curr.size() != 0) ans.push_back(curr);
	    }
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};