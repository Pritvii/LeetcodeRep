class Solution {
public:
    bool solve(vector<int>&nums , int i , int j , int k)
    {
        int a = nums[i];
        int b = nums[j];
        int c = nums[k];
        if(a==0 || b==0|| c==0)
            return false;
        else if(a==b==c)
            return true;
        else if(a == b)
        {   float x = c/2;
            if(a > x)
                return true;
            else
                return false;
        }
        else if(b == c)
        {
            return true;
        }
        else
        {
            if(a + b > c)
                return true;
            else
                return false;
        }
    }
    int largestPerimeter(vector<int>& nums) {
       sort(nums.begin(),nums.end()); 
       int n = nums.size();
        int i = n-3;
        int j = n-2;
        int k = n-1;
        
        for(int p = i ; p >= 0 ; p--)
        {
            if(solve(nums , p  , p + 1 , p + 2))
                return nums[p] + nums[p+1] + nums[p+2];
        }
        return 0;
    }
};