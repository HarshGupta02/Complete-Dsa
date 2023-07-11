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

// METHOD 2: TIME = O(N * LOG(K)), SPACE = O(K)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class cmp{
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < k; i ++) {
            if(lists[i] != NULL) pq.push(lists[i]);
        }
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while(!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            if(node -> next != NULL) pq.push(node -> next);
            curr -> next = node; curr = curr -> next;
        }
        return head -> next;
    }
};