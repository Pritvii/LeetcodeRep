class Solution {
public:
    int solve(int n)
    {return log2(n)+1;
    }
    int concatenatedBinary(int n) {
       
        long MOD = 1e9 + 7 ;
        long ans = 0;
        for(int i = 1 ; i <= n ; i ++)
        {   
            int len = solve(i);
            ans = ((ans<<len % MOD) + i) % MOD;
            //cout<<ans;
            
        }
       return ans;
       
    }
};