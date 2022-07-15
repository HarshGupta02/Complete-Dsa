int countTriplets(DLLNode* head, int target)
{
    DLLNode* p1 = head;
    DLLNode* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    int cnt = 0;
    while(p1 -> next -> next != NULL){
        DLLNode* p2 = p1 -> next;
        DLLNode* p3 = tail;
        while(p2 -> data < p3 -> data){
            int left = p2 -> data;
            int right = p3 -> data;
            int curr = p1 -> data;
            if(curr + left + right > target){
                p3 = p3 -> prev;
            }else if(curr + left + right < target){
                p2 = p2 -> next;
            }else{
                cnt ++;
                p2 = p2 -> next; p3 = p3 -> prev;
            }
        }
        p1 = p1 -> next;
    }
    return cnt;
}