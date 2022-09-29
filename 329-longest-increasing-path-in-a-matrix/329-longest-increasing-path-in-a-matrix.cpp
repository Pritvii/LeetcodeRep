class Solution {
public:
    int ans = 0;
    int dp[201][201];
    int dfs(vector<vector<int>>& matrix , int i , int j , int m , int n , int ak)
    {   
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int curr_ans = 0 ;
        if(i + 1 <= m && i + 1>= 0 && j <= n && j >= 0 && matrix[i+1][j] > matrix[i][j])
        {
           curr_ans = max(curr_ans , 1 + dfs(matrix , i+1 , j , m  , n , ak+1));
        }
        if(i - 1 <= m && i  - 1 >= 0 && j <= n && j >= 0 && matrix[i-1][j] > matrix[i][j])
        {
           curr_ans = max(curr_ans , 1 +  dfs(matrix , i-1 , j , m  , n , ak+1));
        }
        if(i  <= m && i >= 0 && j + 1 <= n && j + 1 >= 0 && matrix[i][j+1] > matrix[i][j])
        {
           curr_ans = max(curr_ans , 1 +  dfs(matrix , i , j + 1 , m  , n , ak + 1));
        }
        if(i  <= m && i >= 0 && j - 1 <= n && j - 1 >= 0 && matrix[i][j-1] > matrix[i][j])
        {
           curr_ans = max(curr_ans , 1 +  dfs(matrix , i, j-1 , m  , n , ak  +1));
        }
        
        return dp[i][j] = curr_ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1;
        int n  = matrix[0].size() - 1;
        
        memset(dp , -1 , sizeof(dp));
        
        for(int i = 0 ; i < matrix.size() ; i ++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j ++)
            {
                ans = max(ans , dfs(matrix , i , j , m , n ,0) ) ;
            }
        }
        
        return ans+1;
    }
};