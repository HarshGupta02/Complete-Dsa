/* METHOD 1:
here we try every possible number that can be the equal number. if we have the 
cost to convert every number to x, then to convert every number to x + 1 is
simply the addition of prefix and suffix sum of the total costs of each number
(considering all the occurences).
*/

class Solution {
public:
    using ll = long long int;
    const ll MAXN = 1e6 + 5;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<ll>total(MAXN, 0);
        for(int i = 0; i < n; i ++) total[nums[i]] += cost[i];
        vector<ll>prefix(MAXN, 0);
        vector<ll>suffix(MAXN, 0);
        ll sum = 0;
        for(int i = 1; i < MAXN; i ++){
            prefix[i] = prefix[i - 1] + sum;
            sum += total[i];
        }
        sum = 0;
        ll ans = 1e18;
        for(int i = MAXN - 2; i >= 0; i --){
            suffix[i] = suffix[i + 1] + sum;
            sum += total[i];
            ans = min(ans, prefix[i] + suffix[i]);
        }
        return ans;
    }
};

/* METHOD 2:
here we try to covert the cost of each element to 1 by increasing the occurences
of each element by it's cost so that each element can have an equal cost of 1
and the question reduces to find the min operations to convert all elements
to a single equal value or element by finding the median of the total occurences
of all the elements.
*/

class Solution {
public:
    using ll = long long int;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<ll,ll>>v;
        for(int i = 0; i < n; i ++) v.push_back({nums[i], cost[i]});
        sort(v.begin(), v.end());
        vector<int>a, b;
        for(int i = 0; i < n; i ++){
            a.push_back(v[i].first); 
            b.push_back(v[i].second);
        }
        ll total = 0;
        for(int i = 0; i < n; i ++) total += cost[i];
        ll mid = total/2, prev = 0, target = 0;
        for(int i = 0; i < n; i ++){
            prev += b[i];
            if(prev >= mid){
                target = a[i];
                break;
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i ++){
            ans += abs(target - a[i]) * b[i];
        }
        return ans;
    }
};