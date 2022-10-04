class LUPrefix {
public:
    set<int>s;
    int max = 0;
    // max denotes the possible candidate for being an index i such that all elements from 1 to i
    // inclusive exists.
    LUPrefix(int n) {
                
    }
    
    void upload(int video) {
        s.insert(video);
        while(s.count(max + 1)) max ++;
    }
    
    int longest() {
        return max;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */