class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        string numm = to_string(num);
        //cout<<numm;
        map<int , int> m;
        
        
        if(num > 0){
        for(int i = 0 ; i  < numm.length() ; i ++)
        {
            m[numm[i] - '0']++;
        }
        }else
        {
            for(int i = 1 ; i  < numm.length() ; i ++)
        {
            m[numm[i] - '0']++;
        }
        }
        
        string ans = "";
        
        if(num >  0 )
        {
            int mini = 9;
            for(auto el : m)
            {   if(el.first!=0)
                mini = min(mini , el.first);
            }
            ans += to_string(mini);
            m[mini]--;
            int num_0 = 0;
            for(int i = 0 ; i < m[0] ; i++)
            {
                ans += "0";
            }
            m[0] = 0;
            for(int i = 1 ; i <= 9 ; i ++)
            {
                if(m[i]!=0)
                {
                    for(int j = 0 ; j < m[i] ; j++ )
                    {
                        ans += to_string(i);
                    }
                }
            }
            
            long long anss = stoll(ans);
            return anss;
        }
        else
        {
            int maxi = 1;
            for(auto el : m)
            {   if(el.first!=0)
                maxi = max(maxi , el.first);
            }
            ans += to_string(maxi);
            m[maxi]--;
            
            for(int i = 9 ; i >=1 ; i --)
            {
                if(m[i]!=0)
                {
                    for(int j = 0 ; j < m[i] ; j++ )
                    {
                        ans += to_string(i);
                    }
                }
            }
            
            int num_0 = 0;
            for(int i = 0 ; i < m[0] ; i++)
            {
                ans += "0";
            }
            m[0] = 0;
            
            long long anss = stoll(ans)*-1;
            return anss;
        }
        
    }
};