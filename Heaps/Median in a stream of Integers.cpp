/*
we know that the numbers less than the median lie on left side of median and numbers
greater than median lie on the right side of the median.

so the median will be the max of left numbers and min of right numbers. hence we 
used 2 priority queues. the diff in queue's can be atmax 1 (0 for even numbers and 
1 for odd numbers). if greater than 1 so move top element from the greater queue
to the smaller queue.

*/

class Solution
{
    public:
    
    priority_queue<int>q1; // max_heap
    priority_queue<int,vector<int>,greater<int>>q2; // min_heap
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(q1.empty() or q1.top() > x) q1.push(x);
        else q2.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int sz1 = q1.size();
        int sz2 = q2.size();
        if(sz1 - sz2 > 1){
            q2.push(q1.top());
            q1.pop();
        }
        if(sz2 - sz1 > 1){
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int sz1 = q1.size();
        int sz2 = q2.size();
        if(sz1 == sz2) return (q1.top() + q2.top())/2.0;
        if(sz1 > sz2) return q1.top()/1.0;
        return q2.top()/1.0;
    }
};