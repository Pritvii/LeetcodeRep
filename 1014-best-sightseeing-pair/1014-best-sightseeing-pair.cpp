class Solution {
public:
    int dp[50001][3];
    int solve(vector<int>& nums , int curr,int k){
        if(curr >= nums.size() && k>0){
            return INT_MIN;
        }
        //include curr or not
        if(dp[curr][k]!=-1)return dp[curr][k];
        int ans = 0;
        
        if(k==2)
        ans = nums[curr] + curr  + solve(nums,curr +1 , k-1);
        
        if(k==1)
        ans = nums[curr] - curr ;
        
        ans = max(ans, solve(nums,curr+1,k));
        
        return dp[curr][k] = ans;
        
    }
    int maxScoreSightseeingPair(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,2);
    }
};