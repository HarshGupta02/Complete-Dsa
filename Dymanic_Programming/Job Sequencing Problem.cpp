class DSU{
  public:
  
  vector<int>parent;
  DSU(int n){
      parent.resize(n + 1);
      for(int i = 0; i <= n ; i ++){
          parent[i] = i;
      }
  }
  
  int get_parent(int a){
      return parent[a] = (parent[a] == a) ? a : get_parent(parent[a]);
  }
  
  void merge_child(int a, int b){
      parent[b] = a; // b will merge into a
  }
  
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<Job>v;
        int max_deadline = 0;
        for(int i = 0; i < n ; i ++){
            v.push_back(arr[i]);
            max_deadline = max(max_deadline , arr[i].dead);
        }
        sort(v.begin() , v.end() , [&](const Job &a , const Job &b) -> bool{
            return a.profit > b.profit;
        });
        DSU dsu(max_deadline);
        int cnt =0 , total = 0;
        for(int i = 0; i < n ; i++){
            int curr_deadline = v[i].dead;
            int empty_slot = dsu.get_parent(curr_deadline);
            if(empty_slot > 0){
                dsu.merge_child(dsu.get_parent(empty_slot - 1) , empty_slot);
                cnt ++; total += v[i].profit;
            }
        }
        return {cnt , total};
    } 

};