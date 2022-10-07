/*
basically here we just take all the times either start or end and sort the times and if
an event starts so we +1 on that time and if an event ends so we -1 on that time. so 
mp[time] > 0 denotes that there are mp[time] number of events that start at time = "time"
and mp[time] < 0 denotes that there are abs(mp[time]) number of events that end at
time = "time".
*/

class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start] += 1; mp[end] -= 1;
        int cnt = 0;
        for(auto it : mp){
            cnt += it.second;
            if(cnt > 2){
                mp[start] -= 1; mp[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */