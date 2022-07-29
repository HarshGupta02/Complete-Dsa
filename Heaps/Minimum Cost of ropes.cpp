class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    using ll = long long int;
    long long minCost(long long arr[], long long n) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(int i =0 ; i < n ; i ++) pq.push(arr[i]);
        ll ans = 0;
        while(pq.size() >= 2){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            pq.push(x + y);
            ans += (x + y);
        }
        return ans;
    }
};