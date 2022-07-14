/*

here we move the slow and fast pointer to find the middle element , then reverse the right half of the list and 
compare left and right half;

*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    struct Node* reverseList(struct Node *head)
    {
        struct Node* p1 = head;
        if(p1 -> next == NULL) return p1;
        struct Node* p2 = p1 -> next;
        p1 -> next = NULL;
        struct Node* p3 = p2 -> next;
        while(p3 != NULL){
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p2 -> next;
        }
        p2 -> next = p1;
        return p2;
    }
    
    bool isPalindrome(Node *head)
    {
        if(head == NULL or head -> next == NULL) return true;
        struct Node* slow = head;
        struct Node* fast = head;
        while(fast -> next != NULL and fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        struct Node* temp = slow -> next;
        slow = reverseList(temp);
        struct Node* dummy = head;
        while(slow != NULL){
            if(dummy -> data != slow -> data) return false;
            slow = slow -> next; dummy = dummy -> next;
        }
        return true;
    }
};