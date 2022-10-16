class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        vector<int > prefix_sum = nums , suffix_sum  = nums;
        for(int i = 1 ; i <  nums.size() ; i ++)
        {
            prefix_sum[i] += prefix_sum[i-1]; 
        }
        for(int i = nums.size()- 2 ; i >=0 ; i--)
        {
            suffix_sum[i]+=suffix_sum[i+1];
        }
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            if(prefix_sum[i] == suffix_sum[i])
                return i;
        }
        return -1;
    }
};