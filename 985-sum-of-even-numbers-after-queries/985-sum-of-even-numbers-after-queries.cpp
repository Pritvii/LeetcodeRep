class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {  
        int sum_even = 0;
        for(int el : nums)
        {
            if(el%2 == 0)
            {
                sum_even+=el;
            }
        }
        
        vector<int> ans;
        
        for(auto el : queries)
        {   cout<<sum_even<<endl;
            int val = el[0];
            int pos = el[1];
            
            int temp = nums[pos];
            nums[pos]+=val;
            
            
            
            if(temp%2 == 0 )
            {   
                if(val%2 == 0){
                sum_even+=val;
                ans.push_back(sum_even);
                    }
                else
                {
                    sum_even-=temp;
                    ans.push_back(sum_even);
                }
            }
            else
            {
                if(abs(val%2) == 1)
                {
                    sum_even+=nums[pos];
                    ans.push_back(sum_even);
                }
                else
                {
                    ans.push_back(sum_even);
                }
            }
        }
        
        return ans;
        
    }
};