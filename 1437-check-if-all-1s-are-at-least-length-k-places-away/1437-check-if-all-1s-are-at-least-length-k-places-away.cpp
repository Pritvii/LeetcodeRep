class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pos = -1*k-1;
        for(int i = 0 ;i < nums.size() ; i ++){
            if(nums[i] == 1){
                int diff = i - pos - 1;
                if(diff < k)
                    return false;
                pos = i;
            }
        }
        return true;
    }
};