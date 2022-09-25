class Solution {
public:
    bool is_prime(long n)
    {   
        for(long i = 2 ; i <= sqrt(n) ; i ++)
        {
            if(n%i == 0)
                return false;
        }
        return true;
    }
    bool isUgly(int n) {
        
        if(n < 0 )
            return false;
        if(n>=1 && n<=6)
            return true;
        
        if(is_prime(n))
            return false;
        for(int i = 2 ; i <= sqrt(n) ; i ++)
        {
            if(is_prime(i) && i!=2 && i!=3 && i!=5)
            {
                if(n%i == 0)
                {
                    return false;
                }    
            }
            if(n%i == 0)
            {
                int k = n/i;
                if(is_prime(k) && k!=2 && k!=3 && k!=5)
                    return false;
            }
        }
        
        return true;
    }
};