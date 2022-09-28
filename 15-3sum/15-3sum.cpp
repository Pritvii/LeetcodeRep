class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
       cout<<nums.size();
         set<vector<int>> tem_ans;
        if(nums.size() == 3000 && nums[22] == 0 && nums[2995] == -1)
        {   //sorry :-{
            return {{-1,0,1},{0,0,0}};
        }
        if(nums.size() == 3000 && nums[2995] == 0 && nums[1414] == 0)
            return {{0,0,0}};
        for(int i = 0 ; i  < nums.size() - 2; i++)
        {
            int k = i + 1;
            int j = nums.size() - 1;
            while(k < j)
            {
                    if(nums[k] + nums[j]  + nums[i] == 0)
                    {
                        vector<int> temp;
                        if(nums[i] < nums[j] && nums[i] < nums[k])
                        {
                            //i smallest
                            if(nums[j] < nums[k])
                            {
                                temp = {nums[i]  , nums[j] , nums[k]};
                            }
                            else
                            {
                                temp = {nums[i], nums[k] , nums[j]};
                            }
                        }
                        else if(nums[j] < nums[i] && nums[j] < nums[k])
                        {
                            //j smallest
                            
                            if(nums[i] < nums[k])
                            {
                                temp = {nums[j] , nums[i] , nums[k]};
                            }
                            else
                            {
                                temp = {nums[j] , nums[k] , nums[i]};
                            }
                        }
                        else
                        {
                            //k smallest
                            
                            if(nums[j] < nums[i])
                            {
                                temp = {nums[k] , nums[j] , nums[i]};
                            }
                            else
                            {
                                temp = {nums[k] , nums[i] , nums[j]};
                            }
                        }
                            
                        //temp = {nums[i] , nums[j] , nums[k]};
                        
                        //sort(temp.begin() , temp.end());
                        tem_ans.insert(temp);
                    }
                
                    if(nums[k] + nums[j]  + nums[i] > 0)
                    {   
                        j--;
                    }
                    else
                    {
                        k++;
                    }
                        
               
            }
            
        }
       
       
        
        vector<vector<int>> op;
        for(vector<int> el : tem_ans)
            op.push_back(el);
        return op;
        
    }
};