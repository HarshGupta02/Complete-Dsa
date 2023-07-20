class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    int nn = arr.size();
	    sort(arr.begin(), arr.end(), [&](const string &a, const string &b) -> bool{
	        string s1 = a + b, s2 = b + a;
	        return s1 > s2;
	    });
	    string ans = "";
	    for(int i = 0; i < nn; i ++) ans += arr[i];
	    return ans;
	}
};