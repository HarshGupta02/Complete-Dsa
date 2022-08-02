/////   here we try to convert all 1's to -1 and 0's to +1 because we need the diff of 
/// #0 - #1 to be max so if ever 0 comes , we increase it's counter and whenever 1 comes
// we decrease it's counter , that's why chose +1 and -1. now just apply kadanes algo on
// updated values. we get the max sum which will be no of zeros which are in excess of 
// number of 1's.

class Solution{
public:	
	int maxSubstring(string S)
	{
	    int n = S.size();
	    int curr = 0 , glob_max = -1e9;
	    for(int i = 0; i < n; i ++){
	        int x;
	        x = (S[i] == '1') ? -1 : 1;
	        curr += x;
	        glob_max = max(glob_max , curr);
	        if(curr < 0) curr = 0;
	    }
	    return (glob_max == -1e9 ? -1 : glob_max);
	}
};