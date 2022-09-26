class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0 ;
        for(int el : nums)
        {   int x = 0;
            int tempsum =  0 ;
            for(int i = 1 ; i <= sqrt(el) ; i ++)
            {
                if(el%i == 0 )
                {   x++;
                    tempsum+=i;
                    if(i != el/i){
                        x++;
                    tempsum+=(el/i);
                    }
                }
            }if(x==4)
            {
                sum+=tempsum;
            }
        }
        return sum;
    }
};