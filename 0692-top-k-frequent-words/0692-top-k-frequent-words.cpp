class Solution {
public:
    static bool cmp(pair<string  , int> a , pair<string , int> b)
    {   if(a.second == b.second)
        {
        return a < b;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string  , int > m;
        
        if(k > words.size())
        {
            sort(words.begin() , words.end());
            return words;
        }
        
        for(string s : words)
        {
            m[s]++;
        }
        vector<pair<string , int> > fin;
        for(auto el  : m)
        {
            fin.push_back({el.first , el.second});
        }
        
        
        
        sort(fin.begin() , fin.end() , cmp);
        
        for(auto el : fin)
        {
            cout<<el.first<<" "<<el.second<<endl;
        }
        
        
        
        vector<string> ans;
        int i = 0;
        while(k--)
        {
            ans.push_back(fin[i].first);
            i++;
        }
        
        //sort(ans.begin() , ans.end());
        
        
        return ans;
    }
};