/*
so here basically we maintain a doubly linked list for each freq possible that 
occured by the elements like maintaining a DLL of all the nodes that appeared once,
that appeared twice and so on. whenever a new get or put request comes for a node
so remove the element from the current list and add the node to the next list.

also the elements in each DLL are added so as to main the LRU CACHE order in case of
a tie occurs for LFU.

*/

struct Node{
    int key, val, cnt;
    Node* prev, *next;
    Node(int key, int val){
        this -> key = key;
        this -> val = val;
        this -> cnt = 1;
        this -> prev = nullptr;
        this -> next = nullptr;
    }
};

struct List{
    int size;
    Node *head, *tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        this -> size = 0;
        head -> next = tail;
        head -> prev = nullptr;
        tail -> prev = head;
        tail -> next = nullptr;
    }
    
    void addNode(Node* toAdd){
        Node* nextNode = head -> next;
        head -> next = toAdd;
        toAdd -> next = nextNode;
        nextNode -> prev = toAdd;
        toAdd -> prev = head;
        size ++;
    }
    
    void deleteNode(Node* toRemove){
        Node* nextNode = toRemove -> next;
        Node* prevNode = toRemove -> prev;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        size --;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> mp;
    unordered_map<int, List*> freq;
    int minFreq, currSize, maxCacheSize;
        
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node *node){
        mp.erase(node -> key);
        freq[node -> cnt] -> deleteNode(node);
        if(node -> cnt == minFreq and freq[node -> cnt] -> size == 0) minFreq ++;
        List *nextHigherFreqList = new List();
        if(freq.find(node -> cnt + 1) != freq.end()){
            nextHigherFreqList = freq[node -> cnt + 1];
        }
        node -> cnt += 1;
        nextHigherFreqList -> addNode(node);
        freq[node -> cnt] = nextHigherFreqList;
        mp[node -> key] = node;
    }
    
    int get(int keyy) {
        if(mp.find(keyy) == mp.end()) return -1;
        Node* node = mp[keyy];
        int res = node -> val;
        updateFreqListMap(node);
        return res;
    }
    
    void put(int keyy, int value) {
        if(maxCacheSize == 0) return;
        if(mp.find(keyy) != mp.end()) {
            Node* foundNode = mp[keyy];
            foundNode -> val = value;
            updateFreqListMap(foundNode);
        }else {
            if(currSize == maxCacheSize){
                List* list = freq[minFreq];
                mp.erase(list -> tail -> prev -> key);
                freq[minFreq] -> deleteNode(list -> tail -> prev);
                currSize --;
            }
            currSize ++;
            minFreq = 1;
            List *newList = new List();
            if(freq.find(minFreq) != freq.end()){
                newList = freq[minFreq];
            }
            Node* newNode = new Node(keyy, value);
            newList -> addNode(newNode);
            mp[keyy] = newNode;
            freq[minFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */