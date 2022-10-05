struct Node{
    Node* links[26];
    int cp = 0;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void increasePrefix(){
        cp ++;
    }
    
    int getPrefix(){
        return cp;
    }
    
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root = new Node();
    }
    
    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i ++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increasePrefix();
        }
    }
    
    int getWordsStarting(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i ++){
            if(!node -> containsKey(word[i])) return 0;
            node = node -> get(word[i]);
        }
        return node -> getPrefix();
    }
};

class Solution{
public:
    
    vector<int> prefixCount(int N, int Q, string li[], string query[]){
        Trie trie;
        vector<int>ans;
        for(int i = 0; i < N; i ++) trie.insert(li[i]);
        for(int i = 0; i < Q; i ++){
            ans.push_back(trie.getWordsStarting(query[i]));
        }
        return ans;
    }
};
