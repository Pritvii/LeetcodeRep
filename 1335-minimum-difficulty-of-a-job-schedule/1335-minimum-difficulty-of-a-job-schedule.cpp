class Solution {
public:
    int dp[305][15];
    long long solve(vector<int>& jd , int curr , int day)
    {   
        
        
        if(day == 0 && curr == jd.size())
            return 0;
        if(day > 0 && curr == jd.size())
            return 999999;
        if(day < 0)
            return 999999;
        
        if(dp[curr][day]!=-1)
            return dp[curr][day];
        
        long long  ans = 999999;
        long long  curr_max = jd[curr];
        ans =  jd[curr] + solve(jd , curr + 1 , day-1);
        
        for(int i = curr+1 ; i < jd.size()  ; i ++)
        {   
            if(curr_max < jd[i])
                curr_max = jd[i];
            
            ans = min(ans , curr_max + solve(jd , i + 1 , day-1)) ;
           
        }
        dp[curr][day] = ans;
        return  ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        if(d > jd.size())return -1;
        memset(dp , -1 , sizeof(dp));
        int ans = solve(jd,0,d);       
        return ans;
    }
};