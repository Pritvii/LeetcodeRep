class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int number_bits_1  =  0 , number_bits_2 = 0 ;
        int temp1 = num1;
        int temp2 = num2;
        int arr1[32] = {0} , arr2[32] = {0} ;
        int temp_arr[32] = {0};
        int i = 0;
        
        while(temp1)
        {   
            if(temp1%2 == 1){
                arr1[i] = 1;
                temp_arr[i] = 1;
                number_bits_1++;
            }
            i++;
            temp1/=2;
        }
        i = 0;
         while(temp2)
        {
            if(temp2%2 == 1){
                arr2[i] = 1;
                number_bits_2++;
            }
            i++;
            temp2/=2;
        }
        
        cout<<number_bits_1<<" "<<number_bits_2<<endl;
        if(number_bits_1 > number_bits_2)
        {
            int diff = number_bits_1  - number_bits_2;
            int j = 0;
            cout<<diff<<endl;
            while(diff > 0)
            {
                if(arr1[j] == 1)
                {   
                    temp_arr[j] = 0;
                    --diff;
                }
                j++;
            }
            
            int ans = 0;
            j = 0;
            for(int i = 0 ; i < 32 ; i ++)
            {   
                if(temp_arr[i] == 1)
                    ans += pow(2 , j);
                j++;
            }
            return ans;
        }
        else if(number_bits_1  <  number_bits_2)
        {
            int diff = number_bits_2 - number_bits_1;
            for(int i = 0 ; i < 32 ; i ++)
            {
                if(temp_arr[i]==0)
                {
                    if(diff>0)
                    temp_arr[i] = 1;
                    
                    diff--;
                }
                
            }
            int ans = 0;
            int j = 0;
            for(int i = 0 ; i < 32 ; i ++)
            {   
                if(temp_arr[i] == 1)
                    ans += pow(2 , j);
                j++;
            }
            return ans;
        }
        else
        {
            return num1;
        }
        
    }
};