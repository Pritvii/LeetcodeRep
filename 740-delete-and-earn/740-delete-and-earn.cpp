class Solution {
public:
    map<int , int > m , cnt ;
    int dp[100001];
    int solve(vector<int>& nums , int curr)
    {   cout<<curr<<endl;
        if(curr  >= nums.size())
        {
        return 0;
        }
     if(dp[curr] != -1)
     {
         return dp[curr];
     }
        int ans = 0 ;
        int ans1  =  0 , ans2  = 0 ;
        int  num = nums[curr];
        
        //inlcluding current
        
        if(m[nums[curr] + 1] != 0)
        {   
            ans1 = nums[curr]*cnt[nums[curr]] + solve(nums , m[nums[curr] + 1]  +  1 );
        }
        else
        {
            ans1 = nums[curr]*cnt[nums[curr]] + solve(nums , m[nums[curr]] + 1);
        }
        
        //excluding current
         ans2 = solve(nums , curr + 1);
        
        
        return dp[curr] = max(ans1 ,ans2);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        for(int  i = 0 ; i < nums.size() ;  i++)
        {
            m[nums[i]] = i;
            cnt[nums[i]]++;
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        memset(dp , -1 , sizeof(dp));
        
        return solve(nums , 0);
    }
};