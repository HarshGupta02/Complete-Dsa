class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head) 
    {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        map<int,int>mp;
        struct Node* prev = head;
        struct Node* curr = head -> next;
        mp[prev -> data] = 1;
        while(curr != NULL){
            int val = curr -> data;
            if(mp[val] == 0){
                mp[val] = 1;
                prev = curr;
            }else{
                prev -> next = curr -> next;
            }
            curr = curr -> next;
        }
        return head;
    }
};