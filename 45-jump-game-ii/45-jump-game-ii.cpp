class Solution {
public:
    int dp[10001];
    int nn;
    int solve(vector<int> &nums , int curr)
    {   //cout<<curr<<endl;
        
        if(curr == nums.size()-1)
        {
            return 0;
        }
        
        if(dp[curr]!= -1)
        {
            return dp[curr];
        }
        
        int ans = 9999;
        for(int i = 1 ; i <= min(nums[curr] , nn - 1 - curr )  ; i ++)
        {   if(curr + i < nums.size()){
            if(dp[curr + i] != -1)
            {
                ans = min(ans ,1 + dp[curr + i]);
                continue;
            }
            ans = min(ans , 1 + solve(nums , curr + i));
            }
            cout<<ans<<endl;
        }           
        return dp[curr] = ans;
        
    }
    int jump(vector<int>& nums) {
        nn = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0);
    }
};