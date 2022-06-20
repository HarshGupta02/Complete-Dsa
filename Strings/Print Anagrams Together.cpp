// TIME = 0(N * |S| * LOG(|S|)) , SPACE = O(N * |S|)

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        int n = string_list.size();
        unordered_map<string,vector<string>>mp;
        for(int i = 0; i < n; i++){
            string curr = string_list[i];
            sort(curr.begin(),curr.end());
            mp[curr].push_back(string_list[i]);
        }
        vector<vector<string>>ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};



/// TIME = 

/*

this method uses prime hashing as if two strings are anagrams then their hash function must be same as so be 
grouped together and so we define primes upto 26 letters like 'a' -> 2 , 'b' -> 3 , 'c' -> 5 , 'd' -> 7 ....
upto 'z' . so we associate each prime number to each english letter and the hash value of a string is calculated
as the product of all the prime numbers corresponding to the characters present in a string.

*/


class Solution {
public:
    
    using ll = long long int;
    
    vector<ll>primes;
    const ll nax = 100;
    const ll MOD = 1e9 + 7;
    bitset<100>visited;
    
    void gen_primes(){
        for(int i = 0; i < nax;i ++){
            visited[i] = 1;
        }
        for(int i = 2 ; i * i<= nax; i++){
            if(visited[i]){
                for(int j = i * i ; j <= nax ;j += i){
                    visited[j] = 0;
                }
            }
        }
        for(ll i = 2;i <= nax;i ++){
            if(visited[i]) primes.push_back(i);
        }
    }
    
    ll prime_hash(string s){
        int n = s.size();
        ll prod = 1;
        for(ll i = 0; i < n; i++){
            prod = (prod * primes[s[i] - 'a']) % MOD;
            prod %= MOD;
        }
        return prod % MOD;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        gen_primes();
        vector<ll>h;
        for(int i = 0; i < strs.size(); i++){
            h.push_back(prime_hash(strs[i]));
        }
        unordered_map<int,vector<string>>mp;
        for(int i = 0; i < h.size(); i ++){
            mp[h[i]].push_back(strs[i]);
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
