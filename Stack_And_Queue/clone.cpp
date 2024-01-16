class LRUCache
{
    private:
        
    public:
    
    class Node{
        public:
            int key;
            int value;
            Node *prev;
            Node *next;
            Node(int _key , int _val){
                key = _key;
                value = _value;
                // prev = NULL;
                // next = NULL;
            }
    };
    
    int total_size_cache;
    unordered_map<int,Node *>mp; /// stores the key and the address
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        total_size_cache = cap;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addNode(Node *new_node){
        Node *temp = head -> next;
        new_node -> prev = head;
        new_node -> next = temp;
        head -> next = new_node;
        temp -> prev = new_node;
        // free(temp);
    }
    
    void delNode(Node *del_node){
        Node *left = del_node -> prev;
        Node *right = del_node -> next;
        left -> next = right;
        right -> prev = left;
        // free(del_node);
    }
    
    
    //Function to return value corresponding to the key.
    int get(int _key)
    {
        if(mp.find(_key) != mp.end()){
            Node *address = mp[_key];
            int original_val = address -> value;
            mp.erase(_key);
            delNode(address);
            addNode(address); // now becomes the last recently used .
            mp[_key] = head -> next;
            return original_val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int _key, int _value)
    {
        if(mp.find(_key) != mp.end()){
            Node *address = mp[_key];
            mp.erase(_key);
            delNode(address);
        }
        if(mp.size() == total_size_cache){
            Node *temp = tail -> prev;
            mp.erase(temp -> key); // so that space is created for the new element in the cache or map.
            delNode(temp);
        }
        addNode(new Node(_key , _value));
        mp[_key] = head -> next;
    }