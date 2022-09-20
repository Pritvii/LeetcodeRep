class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 0;
        }
        if(nums.size() == 2)
        {
            if(nums[0] == nums[1])
            {
                return 1;
            }
            return 0;
        }
        int ans1 = 0  , ans2 = 0;
        int ev_dec = 0;
        
        for(int i  = 1 ; i < nums.size() ; i+=2)
        {   if(i  == nums.size() - 1)
            {   if(nums[i] == nums[i-1])
                {
                    ans1 ++;
                    ans2 ++;
                    break;
                }
                if(nums[i]  > nums[i-1])
                {
                    ans1 += nums[i] - nums[i-1] + 1;
                }
                else
                {
                    ans2 += nums[i-1] - nums[i] + 1;
                }
                break;
            }
                
            if(nums[i] < nums[i-1] || nums[i]  <  nums[i + 1])
            {
                if(nums[i] < nums[i-1] && nums[i]  <  nums[i + 1])
                {
                    ans2 += max(nums[i-1] , nums[i + 1]) - nums[i] + 1;
                }
                else
                {
                        ans1 += nums[i]  - min(nums[i - 1] , nums[i + 1]) + 1;
                        ans2 += max(nums[i-1] , nums[i + 1]) - nums[i] + 1;
                }
            }
            else
            {
                ans1 += nums[i]  - min(nums[i - 1] , nums[i + 1]) + 1;
            }
            
        }      
        
        for(int i  = 0 ; i < nums.size() ; i += 2)
        {   //cout<<ev_dec<<endl;
            if(i == 0)
            {   
                if(nums[0] > nums[1])
                {
                    ev_dec += nums[0] - nums[1] + 1;
                }
                if(nums[0] == nums[1])
                {
                    ev_dec++;
                }
                continue;
            }
            else if(i == nums.size() - 1)
            {
                if(nums[i] > nums[ i-1 ])
                {
                    ev_dec += nums[i] - nums[i-1] + 1;
                }
                continue;
            }
         if(nums[i] == min(nums[i-1] , nums[i + 1]))
         {
             ev_dec++;
             continue;
         }
            if(nums[i] > nums[i-1] || nums[i] > nums[i+1])
            {
                ev_dec += nums[i] - min(nums[i-1] , nums[i+1]) + 1;
            }
            
        }
            
        
        
        
        cout<<ans1<<endl;
        return min(ans1 , ev_dec);
    }
};