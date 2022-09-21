// class Solution {
// public:

// };
class Solution {
public:
    int n;
    bool solve(vector<int>&nums , int curr , vector<int> &dp)
    {   
        if(curr > n-1)
        {
            return false;
        }
        
        if(curr ==n- 1)
        {
            return true;
        }
        
        
        
        if(dp[curr] != -1)
        {   
            return dp[curr];
        }
        for(int i = 1 ;  i <= min ( nums[curr] , n - 1 - curr) ; i ++)
        {  
            if(solve(nums, curr + i , dp ) == true)
            {  
                return dp[curr] = true;
            }
            
        }  
        
        return dp[curr] = false;
        
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int > dp(n-1 , -1);
        return solve(nums , 0 , dp);
    }
};