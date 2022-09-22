class Solution {
public:
    long long int factorial(int n)
    {
        return (n==1 || n==0) ? 1: (n * factorial(n - 1))%(1000000007);
    }
    bool isPrime(int n)
    {
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
    }
    int numPrimeArrangements(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int x = 2 ;
        for(int  i = 4 ; i <=n ; i ++)
        {
            if(isPrime(i))
                x++;
        }
        cout<<x;
        
        
        long long int o1 = factorial(x)   ;
        long long int o2 = factorial(n-x) ;
        
        return (o1*o2)%(1000000007);
        
    }
};