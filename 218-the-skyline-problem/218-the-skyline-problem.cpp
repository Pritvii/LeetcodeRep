class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> st = {0};
        multiset<vector<int>> walls;
         vector<vector<int>> ans;
        int curHeight = 0;
        for(auto ele:buildings){
            walls.insert({ele[0],-ele[2]}); //insert the pairs in multiset as {a,c}
            walls.insert({ele[1],ele[2]});  //insert the pairs in multiset as {b,c}
        };
        
        for(auto w:walls){
            if(w[1] < 0)st.insert(-w[1]);// if wall height is negative   insert its positive val 
            else st.erase(st.find(w[1]));
            
            if(*st.rbegin() != curHeight)
                ans.push_back({w[0],curHeight=*st.rbegin()});
        }
        
        return ans;
    }
};