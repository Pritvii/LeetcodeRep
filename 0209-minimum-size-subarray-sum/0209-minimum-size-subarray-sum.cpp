class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0 ;
        int end = 0 ;
        int ans = INT_MAX;
        int sum = 0;
        int temp = 0 ;
        for(int i = 0 ; i <nums.size() ; i ++)
        {
            temp += nums[i];
        }
        if(temp < target)
            return 0;
            
        while(end < nums.size())
        {
            sum += nums[end];
            if(sum >= target)
            {   cout<<start<<" "<<end<<endl;
                ans = min(ans,end-start+1);
                while(sum >= target)
                {   ans = min(ans,end-start+1);
                    sum-=nums[start];
                    start++;
                }
            }
            end++;
        }
        return ans;
    }
};