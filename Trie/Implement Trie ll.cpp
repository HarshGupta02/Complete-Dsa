#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct Node{
    Node* links[26];
    int ew = 0;
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

    void increaseEnd(){
        ew ++;
    }

    void increasePrefix(){
        cp ++;
    }

    void deleteEnd(){
        ew --;
    }

    void reducePrefix(){
        cp --;
    }

    int getEnd(){
        return ew;
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
        node -> increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i ++){
            if(!node -> containsKey(word[i])) return 0;
            node = node -> get(word[i]);
        }
        return node -> getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i ++){
            if(!node -> containsKey(word[i])) return 0;
            node = node -> get(word[i]);
        }
        return node -> getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i ++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
                node -> reducePrefix();
            }else return;
        }
        node -> deleteEnd();
    }

};

void solve(){

}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}

