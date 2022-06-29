using ll = long long int;
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    ll mini = 0;
    pair<ll,ll>min_pair = {0 , -1};
    for(int i = N - K ; i < N ; i++){
        if(A[i] < 0){
            mini = A[i];
            min_pair = {A[i] , i};
            break;
        }
    }
    vector<ll>ans;
    ans.push_back(mini);
    for(int i = N - K - 1 ;i >= 0; i--){
        if(A[i] < 0){
            min_pair = {A[i] , i};
            ans.push_back(A[i]);
        }else{
            if(min_pair.first == 0){
                ans.push_back(0); continue;
            }
            ll can_reach = i + K - 1;
            if(min_pair.second > can_reach){
                min_pair = {0 , -1};
                ans.push_back(0);
            }else ans.push_back(min_pair.first);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}