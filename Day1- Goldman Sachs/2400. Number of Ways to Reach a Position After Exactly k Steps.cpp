class Solution {
public:
    int f(int s, int i, int j, int k, int e, vector<vector<int>>& dp, int m){
        // i= no. of steps taken, j= currentPos
        if(i==k && j==e) return 1;
        else if(i==k && j!=e) return 0;
    
        if(dp[i][j]!=-1) return dp[i][j];
    
        int left = 0, right = 0;

        left = f(s, i+1, j-1, k, e, dp, m); // it will move 1 step left
        right = f(s, i+1, j+1, k, e, dp, m); // it will move 1 step right  

        return dp[i][j] = (left+right)%m; // total ways to reach end point
    }

    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(k+1, vector<int> (10000, -1));
        int m = 1000000007;
        s = s+1000; // shifting of coordinates to make -ve integers +ve.
        e = e+1000;
        return f(s, 0, s, k, e, dp, m)%m;
    }
};
