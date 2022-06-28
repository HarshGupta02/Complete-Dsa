/// METHOD 1:

class Solution{
    public:
    using ll = long long int;
    long long int maximizeSum(long long int a[], int n, int k)
    {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(int i = 0; i < n ; i ++){
            pq.push(a[i]);
        }
        ll ans = 0;
        while(k > 0){
            ll x = pq.top();
            pq.pop(); pq.push(-1 * x);
            k --;
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};

// 5,4,2,1
// -3

// 20 5 5 5 5 5 5
// -12 -4 -2

// -12 -4 -2 5 5 5 5 5 5 20

// 12 4 2 5 5 5 5 5 5 20


// METHOD 2:

/*

HERE WE FIRST SORT THE ARRAY AND IF THERE IS A NEGATIVE SO MAKE IT POSITIVE.
IF ALREADY POSITIVE THEN DO NOT DO ANY OPERATION. THEN PERFORM ALL THE OPERATIONS
ON THE SMALLEST ELEMENT. EITHER IT DOES NOT CHANGES THE SUM OR CHANGES THE SUM 
BY 2*MINI.

*/

class Solution{
    public:
    using ll = long long int;
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a , a + n);
        for(int i = 0; i < n and k > 0; i ++){
            if(a[i] <= 0){
                a[i] = -1 * a[i]; k --;
            }
        }
        ll mini = *min_element(a , a + n);
        ll sum = 0;
        for(int i = 0 ;i < n ; i++){
            sum += a[i];
        }
        if(k % 2 == 1) sum -= 2 * mini;
        return sum;
    }
};