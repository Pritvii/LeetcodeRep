class Solution {
public:
    static bool cmp(pair<int , int> a , pair<int , int> b){
        return a.first < b.first;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int , int >> m;
        for(int i= 0 ; i < nums.size() ; i++)
            m.push_back({nums[i],i});
        sort(m.begin() , m.end(),cmp);
        for(int i = 0 ; i < nums.size()-1 ; i ++){
            if(m[i].first == m[i+1].first){
                if(abs(m[i].second - m[i+1].second) <= k)
                    return true;
            }
        }
        return false;
    }
};