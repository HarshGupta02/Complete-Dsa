/*
so here we basically insert using map. to remove we see if the element exists in map or not.
if it exists then we swap the val with the last value of the array and then pop back from array and
update the map with the swapped value at prev index.

AVERAGE TIME COMPLEXITY = O(1) FOR EACH OPERATION

*/

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>a;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        a.push_back(val);
        mp[val] = a.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int idx = mp[val];
            int v = a.back();
            a[idx] = v;
            a.pop_back();
            mp[v] = idx;
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return a[rand() % a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */