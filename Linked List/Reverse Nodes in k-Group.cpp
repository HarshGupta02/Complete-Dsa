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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy, *curr = dummy, *nxt = dummy;
        int cnt = 0;
        while(curr -> next != NULL){
            curr = curr -> next;
            cnt ++;
        }
        while(cnt >= k){
            curr = prev -> next;
            nxt = curr -> next;
            for(int i = 0; i < k - 1; i ++){
                curr -> next = nxt -> next;
                nxt -> next = prev -> next;
                prev -> next = nxt;
                nxt = curr -> next;
            }
            prev = curr;
            // here prev always point to the last node of the reversed k-size group
            cnt -= k;
        }
        return dummy -> next;
    }
};