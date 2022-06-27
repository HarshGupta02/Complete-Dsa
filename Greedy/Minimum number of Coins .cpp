/// METHOD 1:

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>den = {1,2,5,10,20,50,100,200,500,2000};
        vector<int>ans;
        for(int i = 9 ; i >= 0 ; i --){
            int cnt = N / den[i];
            N -= (cnt * den[i]);
            while(cnt != 0){
                ans.push_back(den[i]);
                cnt --;
            }
        }
        return ans;
    }
};

/// METHOD 2:

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>den = {1,2,5,10,20,50,100,200,500,2000};
        vector<int>ans;
        while(N > 0){
            auto it = lower_bound(den.begin(),den.end(),N);
            int idx , cnt;
            if(it != den.end()){
                if(*it != N) it --;
                idx = it - den.begin();
            }else idx = 9;
            cnt = N / den[idx];
            N -= cnt * den[idx];
            while(cnt --) ans.push_back(den[idx]);
        }
        return ans;
    }
};