class Solution {
public:
    using ll = long long int;
    long long smallestNumber(long long num) {
        if(num == 0) return 0 * 1ll;
        ll cache = abs(num);
        vector<char>v;
        while(cache > 0){
            ll rem = cache % 10;
            v.push_back(rem + '0');
            cache /= 10;
        }
        if(num > 0) sort(v.begin(), v.end());
        else sort(v.rbegin(), v.rend());
        string temp = "";
        for(auto it : v) temp.push_back(it);
        int i = 0, sz = temp.size();
        while(i < sz and temp[i] == '0') i ++;
        if(i == sz) return 0;
        swap(temp[0], temp[i]);
        ll ans = stoll(temp);
        return num > 0 ? ans : -1 * ans;
    }
};