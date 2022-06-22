class Solution{
  public:
    using ll = long long int;
    long long int floorSqrt(long long int x) 
    {
        ll low = 1 , high = x;
        while(low < high){
            ll mid = low + (high - low)/2;
            if ((mid * mid * 1ll) == x) return mid;
            if((mid * mid *1ll) < x) low = mid + 1;
            else high = mid - 1;
        }
        return (low * low > x) ? low - 1 : low;
    }
};