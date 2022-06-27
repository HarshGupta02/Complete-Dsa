class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>>v;
        for(int i = 0; i < n ; i ++){
            v.push_back({price[i] , i + 1});
        }
        sort(v.begin(),v.end(),[&](const pair<int,int> &a,const pair<int,int> &b) -> bool{
            if(a.first != b.first) return a.first < b.first;
            else return a.second > b.second;
        });
        int ans = 0;
        for(int i = 0 ; i < n and k > 0; i ++){
            if(k < v[i].first) continue;
            int can_buy = k / v[i].first ;
            int p = min(can_buy , v[i].second);
            ans += p;
            k -= p * v[i].first;
        }
        return ans;
    }
};

// maximise number of stocks
// choose that stock which has min price and max i.

// 10 , 1
// 7 , 2
// 19,3

// k = 45

// => sort by min price and then by max i.

// 7,2 ; 10,1 ; 19,3

// 45 - 14 = 31 