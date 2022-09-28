class Solution {
public:
    int left_close = INT_MIN , right_close = INT_MAX ; 
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int ans = INT_MAX;
        int ans_i , ans_j , ans_k;
        for(int i = 0 ; i  < nums.size() - 2; i++)
        {
            int k = i + 1;
            int j = nums.size() - 1;
            while(k < j)
            {
                    if(nums[k] + nums[j]  + nums[i] == target)
                        return target;
                
                    if(nums[k] + nums[j]  + nums[i] > target)
                    {   int temp = ans;
                        ans = min(ans , ((nums[k] + nums[j]  + nums[i]) - target));
                        if(temp!=ans)
                        {
                            ans_i  = i ;
                            ans_j = k;
                            ans_k = j;
                        }
                        j--;
                    }
                    else
                    {
                        int temp = ans;
                        ans = min(ans , (target - (nums[k] + nums[j] + nums[i])));
                        if(temp!=ans)
                        {
                            ans_i  = i ;
                            ans_j = k;
                            ans_k = j;
                        }
                        k++;
                    }
                        
               
            }
            
        }
        int ans_f = nums[ans_i] + nums[ans_j] + nums[ans_k];
        return ans_f;
    }
};