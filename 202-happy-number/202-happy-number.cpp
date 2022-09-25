class Solution {
public:
    map<long  , int> m;
    bool isHappy(int n) {
        
        string s = to_string(n);
    
        if(n == 7)
            return true;
        
        while(m[n]!=2)
        {   cout<<n<<endl;
            m[n]++;
            if(m[n] == 2)
                return false;
            int num = 0 ;
            if(s.length() == 1 && n != 1)
                return false;
            
            for(int i = 0 ; i < s.length() ; i ++)
            {
                num += (s[i]-'0') * (s[i]-'0');
            }
            
            n = num;
            s = to_string(n);
            if(s.length() == 1 && n == 1 || n == 7)
                return true;
        }
        
        return false;
    }
};