class Solution {
public:
    int dp[101];
    int solve(string s , int curr  , string osf)
    {    
        if(s[curr] == '0')
            return 0;
        
        if(curr == s.length())
        {   
            if(osf.length() == s.length()){
                cout<<"ok"<<endl;
                return 1;
            }
            
        }
        if(dp[curr] != -1)
            return dp[curr];
       
        int ans1 = 0 , ans2 = 0 ;
        if(curr < s.length() - 1)
        {
            int num = 0 ; 
            int num1 , num2;
            num1 = s[curr] - '0';
            num2 = s[curr+1] -'0';
            num = num1*10 + num2;
            
            if(num <= 26 && curr + 2 <= s.length() ){
            ans1 =  solve(s , curr + 2 , osf + s[curr] + s[curr + 1]  );
            }
        }
        if(curr + 1 <= s.length()){
            ans2 =   solve(s , curr + 1 , osf + s[curr] );
        }
        cout<<ans1<<" "<<ans2<<endl;
        return dp[curr] = ans1 + ans2;
    
    }
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        memset(dp , -1 , sizeof(dp));
        int ans = solve(s , 0  , "");
        
        
        return ans;
    }
};