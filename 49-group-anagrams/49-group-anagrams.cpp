class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<vector<char> , vector<string>>m;
       for(string el  : strs)
       {
           string temp = el;
           sort(temp.begin() , temp.end());
           vector<char> x;
           for(char ele : temp )
           {
               x.push_back(ele);
           }
           m[x].push_back(el);
       }
       vector<vector<string>> ans;
       for(auto el : m)
       {
           ans.push_back(el.second);
       }
        
        return ans;
    }
};