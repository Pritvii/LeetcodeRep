class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = nums.size()-1;
        int last  = 0;
        
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            if(nums[i] == target)
            {
                last = i;
            }
        }
        
        if(nums.size() == 1)
        {
            if(target!=nums[0])
            {
                return {-1,-1};
            }
            else
            {
                return {0,0};
            }
        }
        
        for(int i = (int)nums.size()-1 ; i>=0 ; i--)
        {
            if(nums[i] == target)
            {
                first = i;
            }
        }
        
        if(first == last)
        {
            return {first, first};
        }
        if(last == 0)
        {
            return {-1,-1};
        }
        
        else
        {
            return {first , last};
        }
    }
};