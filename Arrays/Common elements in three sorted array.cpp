/// TIME = O(N1 + N2 + N3) , SPACE = (N1 + N2 + N3);

class Solution{
public:
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
        unordered_map<int,int>mp;
        unordered_map<int,int>visited;
        vector<int>ans;
        for(int i = 0 ; i < n1 ; i ++){
            if(!visited[A[i]]){
                visited[A[i]] = 1;
                mp[A[i]] ++;
            }
        }
        visited.clear();
        for(int i = 0 ; i < n2 ; i ++){
            if(!visited[B[i]]){
                visited[B[i]] = 1;
                mp[B[i]] ++;
            }
        }
        visited.clear();
        for(int i = 0 ; i < n3 ; i ++){
            if(!visited[C[i]]){
                visited[C[i]] = 1;
                mp[C[i]] ++;
            }
        }
        for(auto it : mp){
            if(it.second == 3) ans.push_back(it.first);
        }
        if(ans.empty()) ans.push_back(-1);
        sort(ans.begin() , ans.end());
        return ans;
    }
};


//// TIME = O(N1 + N2 + N3) , SPACE = O(1)


/* 

HERE WE USE THREE POINTERS I,J,K AT THE BEGIN OF ALL THE THREE ARRAYS AND WE CHECK THAT IF ALL THE THREE NUMBERS ARE
EQUAL OR NOT. IF THEY ARE EQUAL WE CHECK THAT THE ELEMENT WE ARE GOING TO INSERT IS IN THE ANS VECTOR OR NOT(USING ANS.BACK()).
IF ALL ARE NOT EQUAL THEN WE FIND THE MIN OF ALL THE THREE ELEMENTS AND INCREMENT IT'S POINTER BY 1 AS WE CAN STILL BE SURE
TO FIND A COMMON ELEMENT BUT IF WE MOVE THE LARGEST ELEMENT THEN IT IS GURANTEE THAT WE CAN NEVER FIND A COMMON ELEMENT WITH
THE OTHER SMALLER INDEXES.

*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>ans;
            int i = 0 , j = 0 , k = 0;
            while(i < n1 and j < n2 and k < n3){
                if(A[i] == B[j] and B[j] == C[k]){
                    if(ans.size() == 0) ans.push_back(A[i]);
                    else{
                        if(A[i] != ans.back()) ans.push_back(A[i]);
                    }
                    i ++; j ++; k ++; continue;
                }
                if(A[i] < B[j] and A[i] < C[k]){
                    i ++; continue;
                }
                if(B[j] < A[i] and B[j] < C[k]){
                    j ++; continue;
                }
                if(C[k] < A[i] and C[k] < B[j]){
                    k ++; continue;
                }
            }
            if(ans.empty()) ans.push_back(-1);
            return ans;
        }
};