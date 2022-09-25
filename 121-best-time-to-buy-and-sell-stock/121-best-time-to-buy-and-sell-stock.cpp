class Solution {
public:
    int dp[100001][2][2];
    int solve(vector<int>& prices , int curr , int can_buy , int  k)
    {   if(k<=0)
        return 0;
        if(curr == prices.size())
        {
            return 0;
        }
        
        if(  dp[curr][can_buy][k] != -1)
             return dp[curr][can_buy][k];
     
        int ans = 0;
        if(can_buy == 1)
        {
            ans = max(ans ,   solve(prices , curr + 1 , 0 , k) - prices[curr]);
            ans = max(ans , solve(prices , curr + 1 , 1  ,  k) );
            return dp[curr][can_buy][k] = ans;
        }
        if(can_buy == 0)
        {
            ans = max(ans , prices[curr] + solve(prices , curr +1  , 0 , 0));
            ans = max(ans , solve(prices  , curr + 1 , 0 ,k));
             return dp[curr][can_buy][k] = ans;
            
        }
         return dp[curr][can_buy][k] = ans;
    }
    int maxProfit(vector<int>& prices) {
        for(int i = 0 ; i < 100001 ; i ++)
        {
            for(int j = 0; j < 2 ; j ++)
            {
                for(int k = 0 ; k < 2 ; k ++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(prices , 0 , 1 , 1);
        
    }
};