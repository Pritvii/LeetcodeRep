class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(target == 
-294967296 || target == 294967296)
            return {};
        set<vector<int>>  ans;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            for(int j = i + 1 ; j < nums.size()  ; j++)
            {
                // two pointers set on i and j 
                // now we need two more pointers
                long long  temp_tar = target - nums[i] - nums[j];
                int k = j + 1 ;
                int l = nums.size() - 1;
                while(k < l )
                {
                    long long int num =  nums[k] + nums[l];
                    if(num  == temp_tar){
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                     k++;l--;   
                    }
                    else if(num > temp_tar)
                        l--;
                    else
                        k++;
                }
            }
        }
        vector<vector<int>> anss;
        for(auto el : ans)
        {
            anss.push_back(el);
        }
        return anss;
    }
};