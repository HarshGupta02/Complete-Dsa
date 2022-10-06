/*
upper_bound works for unordered_maps also on the basis of key. 
also if an iterator points to mp.end(), we can decrement it to point it to the 
last element or any other element within the bounds.

*/

class TimeMap {
public:
    unordered_map<string, map<int, string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        if(it == mp[key].begin()) return "";
        it --;
        return it -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */