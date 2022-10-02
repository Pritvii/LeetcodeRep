class Solution {
public:
    int dp[31][1001];
    int mod=(int)(1e9+7);
    long long  solve(int n , int  k , int target  , int curr_sum)
    {   cout<<n<<endl;
        if(curr_sum == target && n == 0)
            return 1;
        
        if(curr_sum > target || n <= 0 )
            return 0;
            
        if(dp[n][curr_sum]!=-1)
            return dp[n][curr_sum];
     
        int ans = 0 ;
        
        for(int i = 1  ; i <= k ; i ++ )
        {   
            if(curr_sum + i <= target){
                if(dp[n-1][curr_sum + i]!=-1){
                    ans = (ans%1000000007 + (dp[n-1][curr_sum +  i])%1000000007)%1000000007; 
                    continue;
                }
            ans  = (ans%1000000007 +  (solve(n - 1 , k , target , curr_sum + i ))%1000000007 ) % 1000000007;
            }
        }
        
        return dp[n][curr_sum] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp , -1 , sizeof(dp));
        
        return solve(n , k , target , 0);
    }
};