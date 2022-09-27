class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i = 0 ; i < arr.size() ; i ++)
        {   cout<<i<<endl;
            if(i >= arr.size() - 2 && arr[i] == 0)
            {
                for(int k = i ; k < arr.size() ; k ++)
                {
                    arr[k] = 0;
                }
                return;
            }
            if(arr[i] == 0)
            {
                for(int j = arr.size()-1 ; j >= i + 2 ; j--)
                {
                    arr[j] = arr[j-1];
                }
                
                arr[i+1] = 0;
                i++;
            }
         
        }
    }
};