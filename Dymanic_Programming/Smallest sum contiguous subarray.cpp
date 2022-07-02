class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int n = a.size();
      int curr = 0 , glob_max = -1e9;
      for(int i =0 ; i < n ; i ++){
          a[i] = -1 * a[i];
          curr += a[i];
          glob_max = max(glob_max , curr);
          if(curr < 0) curr = 0;
      }
      return -1 * glob_max;
  }
};