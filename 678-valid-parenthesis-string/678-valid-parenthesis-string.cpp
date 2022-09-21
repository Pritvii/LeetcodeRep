class Solution {
public:
    int dp[101][101][101];
    bool solve(string s, int curr , int front  , int end)
    {   if(end > front )
        {
        return false;
        }
        if(curr == s.length())
        {   if(front  == end)
            return true;
            else
            return false;
        }
     
        if(dp[curr][front][end] != -1)
        {
            return dp[curr][front][end];
        }
        
        bool  ans = false;
        
        if(s[curr] == '(')
        {
            ans  |= solve(s , curr + 1 , front  +1  , end);
            
        }
        else if( s[curr] == ')')
        {
            ans  |= solve(s , curr + 1  , front  , end +1);
        }
        else
        {
        //star
            ans |= solve(s , curr + 1  , front +1  , end ) ;
            if(ans == true)
                return true;
            ans |= solve(s , curr + 1 , front  , end + 1);
            if(ans == true)
                return true;
            ans |= solve(s, curr +1  , front   , end);
            if(ans == true)
                return true;
        }
        
        return dp[curr][front][end] = ans;
        
        
    }
    
    bool checkValidString(string s) {
        memset(dp , -1 , sizeof(dp));
        return solve( s , 0 , 0 , 0 );
    }
};