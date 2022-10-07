/*
we just check the possible where the interval can be inserted because it will lie 
between 2 intervals and we need to check if both the left and the right intervals 
do not intersect with the interval that has to be inserted.

TIME = O(LOG N), SPACE = O(N)

*/

class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end});
        if(it != st.end() and it -> first < end) return false;
        if(it != st.begin() and start < (-- it) -> second) return false;
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */