// here we need to find the min number of elements in the sequence so we try to use bfs and insert
// all elements that differ by one character in the same level of the tree . this ensures that all
// strings are inserted that could be possible by changing just one character by doing brute force.


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string>st;
        for(int i = 0; i < n ; i ++){
            st.insert(wordList[i]);
        }
        if(st.find(endWord) != st.end()){
            queue<string>q;
            q.push(beginWord);
            int depth = 1;
            while(!q.empty()){
                int level = q.size();
                while(level --){
                    string curr_word = q.front();
                    q.pop();
                    for(int i = 0 ; i < curr_word.size(); i ++){
                        string temp = curr_word;
                        for(char ch = 'a' ; ch <= 'z'; ch ++){
                            if(ch == temp[i]) continue;
                            temp[i] = ch;
                            if(st.find(temp) != st.end()){
                                if(temp == endWord) return depth + 1;
                                q.push(temp);
                                st.erase(st.find(temp));
                            }
                        }
                    }
                }
                depth ++;
            } 
        }
        return 0;
    }
};