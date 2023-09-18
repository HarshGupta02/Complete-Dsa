struct Node{
    Node* links[2];

    bool isContainsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie{
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i --) {
            int bit = (num >> i) & 1;
            if(!(node -> isContainsKey(bit))) {
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }
    int get_max(int num) {
        Node* node = root;
        int ans = 0;
        for(int i = 31; i >= 0; i --) {
            int bit = (num >> i) & 1;
            if(node -> isContainsKey(1 - bit)) {
                ans = ans | (1 << i);
                node = node -> get(1 - bit);
            }else node = node -> get(bit);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(int i = 0; i < n; i ++) trie.insert(nums[i]);
        int ans = 0;
        for(int i = 0; i < n; i ++) ans = max(ans, trie.get_max(nums[i]));
        return ans;
    }
};