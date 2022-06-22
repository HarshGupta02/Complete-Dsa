pair<long long, long long> getMinMax(long long a[], int n) {
    pair<ll,ll>p;
    if(n % 2 == 0){
        if(a[0] >= a[1]){
            p.first = a[1]; p.second = a[0];
        }else{
            p.first = a[0]; p.second = a[1];
        }
    }else{
        p.first = a[0]; p.second = a[0];
    }
    for(int i = (n % 2 == 0) ? 2 : 1 ; i < n ; i += 2){
        if(a[i] > a[i + 1]){
            if(a[i] >= p.second){
                p.second = a[i];
            }
            if(a[i + 1] <= p.first){
                p.first = a[i + 1];
            }
        }else{
            if(a[i] <= p.first){
                p.first = a[i];
            }
            if(a[i + 1] >= p.second){
                p.second = a[i + 1];
            }
        }
    }
    return p;
}