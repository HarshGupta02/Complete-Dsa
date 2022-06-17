// Can be done in O(N) using KMP algorithm.

// O(N ^ 2)

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            string temp = s;
            for(int j = 0; j < n; j++){
                s[(j + 1) % n] = temp[j];
            }
            if(s == goal) return true;
        }
        return false;
    }
};

// O(N ^ 2)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        string temp = s + s;
        if(temp.find(goal) != -1) return true;
        return false;
    }
};