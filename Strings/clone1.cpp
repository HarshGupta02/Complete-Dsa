    #include<bits/stdc++.h>
    using namespace std;

    const int MAXN=1e5+5;

    int t[4*MAXN];  /// stores the sum of its node range
    bool lazy[4*MAXN]; // tells if a certain node is storing any unpropogated update or not
    int upd[4*MAXN]; // stores the value of the unpropogated updates

    void build(vector<int>a,int v,int tl,int tr){
        if(tl==tr){
            t[v]=a[tl];
            return;
        }
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }

    // this is the process of telling the man to remember "val"
    void apply(int v,int tl,int tr,int val){
        t[v]+=val*(tr-tl+1);
        if(tl!=tr){ // if it is not leaf so mark it lazy
            lazy[v]=true;
            upd[v]+=val;
        }
    }

    //assigning the task to both his employees to remember upd[v] that he stored initially
    void pushdown(int v,int tl,int tr){
        if(lazy[v]){
            lazy[v]=false;
            int tm=(tl+tr)/2;
            apply(2*v,tl,tm,upd[v]);
            apply(2*v+1,tm+1,tr,upd[v]);
            upd[v]=0;
        }
    }

    void update(int v,int tl,int tr,int l,int r,int val){
        if(tl>r or tr<l){   /// no overlap
            return;
        }
        if(tl>=l and tr<=r){ //// fully overlap and ask the man to remember the val
            apply(v,tl,tr,val);
            return;
        }  
        pushdown(v,tl,tr);   // partial overlap 
        int tm=(tl+tr)/2; 
        update(2*v,tl,tm,l,r,val);
        update(2*v+1,tm+1,tr,l,r,val);
        t[v]=t[2*v]+t[2*v+1];
    }

    int sum(int v,int tl,int tr,int l,int r){
        if(tl>r or tr<l){
            return 0;
        }
        if(tl>=l and tr<=r){
            return t[v];
        }
        pushdown(v,tl,tr); //we remove lazy tag before going down so that the children have correct information
        int tm=(tl+tr)/2;
        int ans=0;
        ans+=sum(2*v,tl,tm,l,r);
        ans+=sum(2*v+1,tm+1,tr,l,r);
        return ans;
    }


    int main(){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        build(a,1,0,n-1);
        update(1,0,n-1,2,5,3);
        for(auto it : a) cout << it << " ";
        // cout<<sum(1,0,n-1,1,3)<<endl;
        return 0;
    }