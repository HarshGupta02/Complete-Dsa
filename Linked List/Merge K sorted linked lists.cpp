class Solution{
  public:
    //Function to merge K sorted linked list.
    
    Node* sortedMerge(Node* head1, Node* head2)  
    {
        Node* p1 = head1;
        Node* p2 = head2;
        Node* head = new Node(-1);
        Node* prev = head;
        while(p1 != NULL and p2 != NULL){
            int upper = p1 -> data;
            int lower = p2 -> data;
            if(upper <= lower){
                Node* nxt = p1 -> next;
                p1 -> next = p2;
                prev -> next = p1;
                prev = p1;
                p1 = nxt;
            }else{
                Node* nxt = p2 -> next;
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
    
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node**,vector<Node**>,greater<Node**>> pq;
        for(int i = 0; i < K; i ++){
            pq.push(&arr[i]);
        }
        Node* curr = *pq.top();
        pq.pop();
        while(!pq.empty()){
            Node* tp = *pq.top();
            curr = sortedMerge(curr,tp);
            pq.pop();
        }
        return curr;
        // while(!pq.empty()){
        //     Node* tp = *pq.top();
        //     while(tp != NULL){
        //         cout << tp -> data << " ";
        //         tp = tp -> next;
        //     }
        //     pq.pop();
        // }
        // return NULL;
    }
};