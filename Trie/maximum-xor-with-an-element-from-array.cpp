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
        if(node == NULL) return -1;
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<vector<int>> v;
        vector<int> ans(m);
        for(int i = 0; i < m; i ++) v.push_back({queries[i][0], queries[i][1], i});
        sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        sort(nums.begin(), nums.end());
        Trie trie;
        int i = 0;
        bool empty = true;
        for(int j = 0; j < m; j ++) {
            int xj = v[j][0], mj = v[j][1], idx = v[j][2];
            while(i < n and nums[i] <= mj) {
                empty = false;
                trie.insert(nums[i]);
                i ++;
            }
            if(empty) ans[idx] = -1;
            else ans[idx] = trie.get_max(xj);
        }
        return ans;
    }
};