class Solution{
public:

    struct TrieNode{
        TrieNode* child[26];
        bool isEnd;
        TrieNode(){
            for(int i = 0; i < 26; i ++) child[i] = NULL;
            isEnd = false;
        }
    };
    
    class Trie{
        TrieNode* root;
        public:
            Trie(){
                root = new TrieNode();
            }
            
            void insert(string &word){
                TrieNode* curr = root;
                for(int i = 0; i < word.size(); i ++){
                    if(curr -> child[word[i] - 'a'] == NULL){
                        curr -> child[word[i] - 'a'] = new TrieNode();
                    }
                    curr = curr -> child[word[i] - 'a'];
                }
                curr -> isEnd = true;
            }
            
            void dfs(string s, TrieNode* curr, vector<string> &ans){
                if(curr -> isEnd == true){
                    ans.push_back(s); 
                    // return; why not return ??
                }
                for(int i = 0; i < 26; i ++){
                    if(curr -> child[i] != NULL){
                        s += ('a' + i);
                        dfs(s, curr -> child[i], ans);
                        s.pop_back();
                    }
                }
            }
            
            vector<string> getAll(string word){
                TrieNode* curr = root;
                for(int i = 0; i < word.size(); i ++){
                    if(curr -> child[word[i] - 'a'] == NULL) return {"0"};
                    curr = curr -> child[word[i] - 'a'];
                }
                vector<string>ans;
                dfs(word, curr, ans);
                return ans;
            }
            
    };

    vector<vector<string>> displayContacts(int n, string contact[], string s){
        int m = s.size();
        vector<vector<string>> ans;
        Trie trie;
        for(int i = 0; i < n; i ++) trie.insert(contact[i]);
        string p = "";
        for(int i = 0; i < m; i ++){
            p.push_back(s[i]);
            ans.push_back(trie.getAll(p));
        }
        return ans;
    }
};