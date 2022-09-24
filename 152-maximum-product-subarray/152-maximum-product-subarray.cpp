class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int curr_max = 1 , curr_min = 1;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            
            int temp  = curr_max;
            curr_max = max(nums[i]*curr_max , max(nums[i]*curr_min , nums[i]));
            curr_min = min(nums[i]*temp , min(nums[i]*curr_min , nums[i])) ;
            
            ans = max(ans , curr_max);
        }
        
        return ans;
        
       
    }
};