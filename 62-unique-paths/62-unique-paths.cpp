class Solution {
public:
    int dp[101][101];
    bool is_ok(int i , int j , int  m , int  n)
    {
        if(i <= m && j <= n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int solve(int i , int j ,  int  m , int n)
    {   
        if(i == m && j == n )
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0 ;
        
        if(is_ok(i + 1 , j  , m , n))
        {
            ans +=  solve(i + 1  , j , m , n );
        }
        
        if(is_ok(i , j +1 , m , n ))
        {
            ans +=  solve(i , j +1  , m , n );
        }
        
        return dp[i][j] =  ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , m - 1, n - 1 );
    }
};