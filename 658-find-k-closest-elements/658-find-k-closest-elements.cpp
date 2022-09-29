class Solution {
public:
    static bool comp (pair<int , int > a , pair<int , int > b)
    {   if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int , int > m;
        vector<int> ans;
        for(int i = 0 ; i < arr.size() ; i ++)
        {
            m[i] = abs(x - arr[i]);
        }
        vector<pair<int ,int > >  ansp;
        for(auto el : m)
        {
            ansp.push_back({el.first , el.second});
        }
        sort(ansp.begin() , ansp.end() , comp);
        for(int i =0  ; i < k ; i ++)
        {
            ans.push_back(arr[ansp[i].first]);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};