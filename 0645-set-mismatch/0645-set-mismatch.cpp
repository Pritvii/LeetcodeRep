class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       map<int,  int> x;
        int  n = nums.size();
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            x[nums[i]]++;
        }
        int rep = 0;
        for(auto el : x){
            if(el.second == 2){
                rep = el.first;
            }
        }
        for(int i = 1 ; i <= n ; i  ++){
            if(x.find(i) == x.end()){
                return {rep , i};
            }
        }
        return {};
    }
};