class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //iterative dp
        //int ans = -10000;
        int dp[nums.size()];
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i ++){
            int num = dp[i-1] + nums[i];
            int curr = nums[i];
            if(nums[i] > num)
                dp[i] = nums[i];
            else
                dp[i] = num;
        }
        int ans = INT_MIN;
        for(int i =  0 ; i< nums.size() ; i ++)
        {
            ans = max(ans  , dp[i]);
        }
        return ans;
    }
};