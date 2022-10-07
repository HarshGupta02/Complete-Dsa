class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start] += 1; mp[end] -= 1;
        int maxi = -1, active = 0;
        for(auto it : mp){
            active += it.second;
            maxi = max(maxi, active);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */