class Solution {
public:
    int dp[101][3];
    int solve(vector<int> nums , int curr , string inc)
    {   cout<<curr<<endl;
        if(curr >= nums.size())
        {
            return 0;
        }
        if(curr == nums.size() - 1)
        {   if(inc.length() > 0){
            if(inc[0] == '0')
            {
                return 0;
            }
            else
            {
                return nums[curr];
            }
        }
         return nums[curr];
        }
     int x;
     if(inc.length() > 0)
     {
         if(inc[0] == '0')
         {
             x = 1;
         }
         else
         {
             x = 0;
         }
     }
     else
     {
         x = 0 ;
     }
     if(dp[curr][x] != -1)
     {
         return dp[curr][x];
     }
        
        int ans1 = nums[curr] + solve(nums  , curr+2 , inc + to_string(curr));
        int ans2 = solve(nums , curr+1 , inc);
        
        if(ans1  >ans2)
        {
            if(inc[0] == '0')
            {
                return dp[curr][1] = ans1;
            }
            else
            {
                return dp[curr][0] = ans1;
            }
        }
        else
        {
            if(inc[0] == '0')
            {
                return dp[curr][1] = ans2;
            }
            else
            {
                return dp[curr][0] = ans2;
            }
        }
    }
    int rob(vector<int>& nums) {
        if(nums.size() <= 2)
        {
            if(nums.size() == 1)
            {
                return nums[0];
            }
            else if(nums.size() == 2)
            {
                return max(nums[0] , nums[1]);
            }
        }
        for(int i = 0 ; i < 101 ; i ++)
        {
            for(int j = 0  ; j  <3 ; j ++)
            {
                dp[i][j] = -1;
            }
        }
       return solve(nums , 0  , "");
    }
};