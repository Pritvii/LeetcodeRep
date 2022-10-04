class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , cmp);
        vector<vector<int>> what_to_merge;
        for(int i = 0; i  < intervals.size() ; i ++)
        {   //cout<<i
            vector<int> temp;
            temp.push_back(i);
            int j = i;
            int range_max = intervals[i][1];
            while(i < intervals.size() - 1 && range_max >= intervals[i+1][0] )
            {   
                //merge
                i++;
                range_max = max(range_max , intervals[i][1] );
                
            }
            for(int k = j + 1 ; k <= i ; k++)
            {
                temp.push_back(k);
            }
            //i = j;
            what_to_merge.push_back(temp);
        }
        vector<vector<int>> ans;
        for(auto el : what_to_merge)
        {
            vector<int> temp = el;
            int k = el.size();
            int i = intervals[el[0]][0];
            int j = intervals[el[0]][1];
            for(int elo : el)
                {
                j = max( j , intervals[elo][1]);
            }
            ans.push_back({i,j});
        }
        return ans;
    }
};