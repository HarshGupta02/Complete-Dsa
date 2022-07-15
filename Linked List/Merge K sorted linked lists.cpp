class Solution {
public:
    
    ListNode* sortedMerge(ListNode* head1, ListNode* head2)  
    {
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* head = new ListNode(-1);
        ListNode* prev = head;
        while(p1 != NULL and p2 != NULL){
            int upper = p1 -> val;
            int lower = p2 -> val;
            if(upper <= lower){
                ListNode* nxt = p1 -> next;
                p1 -> next = p2;
                prev -> next = p1;
                prev = p1;
                p1 = nxt;
            }else{
                ListNode* nxt = p2 -> next;
                p2 -> next = p1;
                prev -> next = p2;
                prev = p2;
                p2 = nxt;
            }
        }
        while(p1 != NULL){
            prev -> next = p1;
            prev = p1; p1 = p1 -> next;
        }
        while(p2 != NULL){
            prev -> next = p2;
            prev = p2; p2 = p2 -> next;
        }
        head = head -> next;
        head1 = head;
        return head1;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int K = arr.size();
        if(K == 0) return NULL;
        ListNode* curr = arr[0];
        int i = 1;
        while(i < K){
            ListNode* tp = arr[i];
            curr = sortedMerge(curr,tp);
            i ++;
        }
        return curr;
    }
};