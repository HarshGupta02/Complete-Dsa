/// METHOD 1 : TIME = O(N * 100) , SPACE = O(N);

// SORTED ON THE BASIS OF PROFIT AS NEEDED MAX PROFIT , BUT IF NEEDED TO MAXIMISE THE 
// NUMBER OF JOBS DONE , THEN SORT ON BASIS OF DEADLINE.

class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        bitset<105>visited;
        vector<Job>v(n);
        for(int i = 0 ; i < n ; i ++) v[i] = arr[i];
        sort(v.begin() , v.end() , [&](const Job &a , const Job &b) -> bool{
            return a.profit > b.profit;
        });
        int cnt = 0, total_profit = 0;
        for(int i = 0; i < n ; i ++){
            int curr_deadline = v[i].dead;
            for(int j = min(n , curr_deadline); j >= 1; j --){
                if(!visited[j]){
                    visited[j] = 1;
                    total_profit += v[i].profit;
                    cnt ++;
                    break;
                }
            }
        }
        vector<int>ans; ans.push_back(cnt); ans.push_back(total_profit);
        return ans;
    } 
};


/// METHOD 2 : TIME = O(N * LOGN) , SPACE =  O(N).


class Disjoint_Set_Union{
    public :
    vector<int>parent;
    // parent[i] = stores the just immediate empty location for the element to be inserted. 
    // so avoid union by rank.
    Disjoint_Set_Union(int n){
        parent.resize(n + 1);
        for(int i = 0; i <= n ; i ++) parent[i] = i;
    }
    int Dsu_find(int a){
        return parent[a] = (parent[a] == a) ? a : Dsu_find(parent[a]);
    }
    void Dsu_merge(int a, int b){
        parent[b] = a;
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        vector<Job>v(n);
        int max_deadline = -1;
        for(int i = 0; i < n ; i ++){
            v[i] = arr[i]; max_deadline = max(max_deadline, v[i].dead);
        }
        sort(v.begin() , v.end() , [&](const Job &a ,const Job &b) -> bool{
           return a.profit > b.profit; 
        });
        Disjoint_Set_Union ds(max_deadline);
        int cnt = 0 , total_profit = 0;
        for(int i = 0 ; i < n ; i ++){
            int empty_slot = ds.Dsu_find(v[i].dead);
            if(empty_slot > 0){
                ds.Dsu_merge(ds.Dsu_find(empty_slot - 1) , empty_slot);
                cnt ++; total_profit += v[i].profit;
            }
        }
        vector<int>ans; ans.push_back(cnt); ans.push_back(total_profit);
        return ans;
    } 
};


