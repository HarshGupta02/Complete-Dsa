class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        struct Node* tail = head;
        while(tail -> next != NULL){
            tail = tail -> next;
        }
        while(head -> data < tail -> data){
            int left = head -> data;
            int right = tail -> data;
            if(left + right > target){
                tail = tail -> prev;
            }else if(left + right < target){
                head = head -> next;
            }else{
                ans.push_back({head -> data , tail -> data});
                head = head -> next; tail = tail -> prev;
            }
        }
        return ans;
    }
};