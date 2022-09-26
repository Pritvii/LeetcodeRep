class Solution {
public:
    set<int> nu;
    vector<string > ans;
    void solve(vector<int> & nums  , int curr  , string osf  )
    {
        if(curr  == nums.size() )
        {
            ans.push_back(osf);
        }
        
        for(int i  = 0 ; i < nums.size() ; i ++)
        {   
           
            
            if(nu.find(nums[i]) == nu.end())
            {
                nu.insert(nums[i]);
                
                solve(nums , curr + 1 , osf + to_string(nums[i]) + " " );
                
                nu.erase(nu.find(nums[i]));
            }
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums , 0 , "");
        //cout<<ans.size();
        // string s = "-1";
        //     int num  = stoi(s);
        //cout<<num<<endl;
        vector<vector<int>> sol;
        for(string el : ans)
        {   vector<int> x;
            
            for(int i = 0 ; i < el.length() ; i ++)
            {
                string s = "";
                while(el[i]!=' ')
                {
                    s+=el[i];
                    i++;
                }
                x.push_back(stoi(s));
            }
         sol.push_back(x);
        }
        for(string el : ans)
            cout<<el<<endl;
        return sol;
    }
};