/// METHOD 1: TIME = O(N) , SPACE = O(N)

class Solution{
  public:
    using ll = long long int;
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<ll>prefix(n , 1); prefix[0] = nums.front();
        for(int i = 1; i < n ; i ++) prefix[i] = prefix[i - 1] * nums[i];
        vector<ll>suffix(n , 1); suffix[n - 1] = nums.back();
        for(int i = n - 2; i >= 0 ; i --) suffix[i] = suffix[i + 1] * nums[i];
        vector<ll>ans;
        for(int i = 0; i < n ; i ++){
            ll p = 1;
            if(i - 1 >= 0) p *= prefix[i - 1];
            if(i + 1 < n) p *= suffix[i + 1];
            ans.push_back(p);
        }
        return ans;
    }
};

/// METHOD 2 : TIME = O(N) , SPACE = O(1)

// JUST STORED THE PREFIX IN ANSWER ARRAY AS DOES NOT COUNT IN SPACE COMPLEXITY AND ITERATED
// FROM BACK AND CALCULATED THE SUFFIX PRODUCT USING LOOP AND FOUND THE ANS.

class Solution{
  public:
    using ll = long long int;
    
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<ll>ans;
        ll prod = 1;
        for(int i = 0 ; i < n ; i ++){
            prod *= nums[i];
            ans.push_back(prod);
        }
        prod = 1;
        for(int i = n - 1; i >= 0; i--){
            if(i - 1 >= 0){
                ans[i] = ans[i - 1] * prod;
                prod *= nums[i];
            }
        }
        ans[0] = prod;
        return ans;
    }
};