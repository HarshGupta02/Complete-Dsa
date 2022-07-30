// METHOD 1: TIME = O(N * M) , SPACE = O(1).

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    for(int j = 0; j < m ; j ++){
	        for(int i = 0; i < n ; i ++){
	            if(arr[i][j] == 1) return i;
	        }
	    }
	    return -1;
	}

};

// METHOD 2: TIME = O(N * LOG M) , SPACE = O(1)

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1 , nax = -1;
	    for(int i = 0; i < n ; i ++){
	        auto it = lower_bound(arr[i].begin(),arr[i].end(),1);
	        if(it != arr[i].end()){
	            int idx = it - arr[i].begin();
	            if((m - idx) > nax){
	                nax = m - idx;
	                ans = i;
	            }
	        }
	    }
	    return ans;
	}

};

// METHOD 3: TIME = O(N + M) , SPACE = O(1)

/*
here we assumed that we traverse from back and we count number of ones in the first
row. then in the next row , we directly see the element which is one element behind
the the first one in the last row because if there is a zero , then our max ones 
will not change but if there is a one so then we iterate for how many more one's are
there.
*/

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1 , ones = 0;
	    int i = 0 , j;
	    while(i < n){
	        j = m - 1 - ones;
	        while(j >=0 and arr[i][j] == 1){
	            ans = i;
	            ones ++; j --;
	        }
	        i ++;
	    }
	    return (ones == 0) ? -1 : ans;
	}

};

