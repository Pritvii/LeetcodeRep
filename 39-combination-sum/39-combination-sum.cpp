class Solution {
public:
    set<string> ans;
    void solve(vector<int>& candidates , int target , int curr , string osf ,  int sum )
    {   
        
        if(curr == candidates.size())
        {
            if(sum == target)
                ans.insert(osf);
        
                return;
        }
        if(sum == target)
            ans.insert(osf);
        
        
        
        solve(candidates , target , curr + 1  , osf  , sum );
        
        if(sum + candidates[curr] <= target )
        solve(candidates , target , curr , osf + to_string(candidates[curr]) + " " , sum + candidates[curr]);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates , target  , 0 , "", 0);
        cout<<ans.size()<<endl;
        vector<vector<int>> answ;
        for(string el : ans)
        {   vector<int> x;
            for(int i = 0  ; i < el.length() ; i ++)
            {   string temp = "";
                while(el[i]!=' ')
                {
                    temp+=el[i];
                    i++;
                }
                int num = stoi(temp);
                x.push_back(num);
            }
            answ.push_back(x);
        }
        return answ;
    }
};