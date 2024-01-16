#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> assignCrops(int rows, int columns, vector<int> crops, vector<char> types) {
    int dir = 0;
    int left = 0, right = rows - 1, top = 0, down = columns - 1;
    int size = crops.size();
    int k = 0;
    vector<vector<char>> garden(rows, vector<char> (columns));
    while(left <= right and top <= down) {
        if(dir == 0) {
            for(int i = left; i <= right; i ++) {
                if(crops[k] == 0) k ++;
                crops[k] --;
                garden[top][i] = types[k];
            }
            top ++;
        }else if(dir == 1) {
            for(int i = top; i <= down; i ++) {
                if(crops[k] == 0) k ++;
                crops[k] --;
                garden[i][right] = types[k];
            }
            right --;
        }else if(dir == 2) {
            for(int i = right; i >= left; i --) {
                if(crops[k] == 0) k ++;
                crops[k] --;
                garden[down][i] = types[k];
            }
            down --;
        }else {
            for(int i = down; i >= top; i --) {
                if(crops[k] == 0) k ++;
                crops[k] --;
                garden[i][left] = types[k];
            }
            left ++;
        }
        dir = (dir + 1) % 4;
    }
    return garden;
}

int main(){
    vector<int> crops = {5,5,2};
    vector<char> types = {'T','P','C'};
    vector<vector<char>> ans = assignCrops(3,4,crops, types);
    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}