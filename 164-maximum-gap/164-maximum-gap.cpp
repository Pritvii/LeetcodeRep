class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> numss;
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            numss.insert(nums[i]);
        }
        vector<int> n;
        for(int el : numss)
        {
            n.push_back(el);
        }
        int diff = 0;
        for(int i = 0 ; i < n.size() -1  ; i ++)
        {
            diff = max(diff , n[i + 1] - n[i] );
        }
        
        return diff;        
    }
};