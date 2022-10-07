class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& obs , int i , int j , int m , int n )
    {   
        if(i == m && j == n)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0 ;
        
        if(i + 1 >= 0 && i+1 <= m && j >=0 && j <= n && obs[i+1][j] == 0)
            ans+=solve(obs , i + 1 , j , m , n );
        
        if(i >= 0 && i <= m && j + 1 >= 0 && j + 1 <= n && obs[i][j+1] == 0)
            ans+=solve(obs , i , j + 1, m , n );
        
        return dp[i][j] = ans;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        memset(dp , -1 , sizeof(dp));
        if(obs[0][0] == 1)
            return 0;
        int m = obs.size();
        int n = obs[0].size() ;
        return solve(obs , 0 , 0 , m-1 , n-1);
    }
};
