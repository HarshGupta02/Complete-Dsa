// METHOD 1 : HERE WE CREATE A DEEPCOPY OF EACH NODE FIRST AND STORE IN MAP AND THEN ASSIGN NEXT AND RANDOM POINTERS ONLY TO
// THE DEEP COPY OF THE CURR NODES AND NOT THE ORIGINAL NODES.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mp;
        Node* curr = head;
        while(curr != NULL){
            Node* new_node = new Node(curr -> val);
            mp[curr] = new_node;
            curr = curr -> next;
        }
        curr = head;
        while(curr != NULL){
            if(curr -> next == NULL) mp[curr] -> next = NULL;
            else mp[curr] -> next = mp[curr -> next];
            if(curr -> random == NULL) mp[curr] -> random = NULL;
            else mp[curr] -> random = mp[curr -> random];
            curr = curr -> next;
        }
        return mp[head];
    }
};

/*
METHOD 2: HERE WE CREATE A DEEP COPY OF EACH NODE AND INSERT IN BETWEEN THE ORIGINAL NODES. THEN WE ASSIGN THE NEXT AND RANDOM
POINTERS USING THE DEEP COPY OF THE CURR NODES. THEN WE TRY TO SEPARATE BOTH THE LIST BY REMOVING THE LINKS BETWEEN THE 
TWO LISTS.
*/

class Solution
{
    public:
    Node *copyList(Node *head)
    {
        Node* curr = head;
        while(curr != NULL){
            Node* new_node = new Node(curr -> data);
            Node* nxt = curr -> next;
            curr -> next = new_node;
            new_node -> next = nxt;
            curr = nxt;
        }
        
        curr = head;
        while(curr != NULL){
            if(curr -> arb == NULL) curr -> next -> arb = NULL;
            else curr -> next -> arb = curr -> arb -> next;
            curr = curr -> next -> next;
        }
        Node* dummy = new Node(-1); Node* prev = dummy;
        curr = head;
        while(curr != NULL){
            Node* nxt = curr -> next -> next;
            prev -> next = curr -> next;
            prev = curr -> next;
            curr -> next = nxt;
            curr = nxt;
        }
        dummy = dummy -> next;
        return dummy;
    }
};