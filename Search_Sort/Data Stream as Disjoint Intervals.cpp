/*
so here we thought of inserting all elements to an array and then sorting the array and then
considering all intervals so that the interval contains consecutive elements and if not so create
a new interval. but this method uses sorting each time which is not optimised.

so we use set as it takes care of duplicate elements which is not in case of array plus
it stores value in sorted order so no need to sort otherwise and then again check for
consecutive elements by iterating over the values of set and creating intervals on the
go.

TIME = O(N * LOGN), SPACE = O(N).

*/

class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int left = -1, right = -1;
        for(auto val : st){
            if(left < 0){
                left = val; right = val;
            }else if(val == (right + 1)){
                right = val;
            }else {
                ans.push_back({left, right});
                left = val;
                right = val;
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */