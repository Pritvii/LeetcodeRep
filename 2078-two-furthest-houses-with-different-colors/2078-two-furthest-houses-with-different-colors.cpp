class Solution {
public:
    int maxDistance(vector<int>& c) {
        int ans = INT_MIN ; 
        for(int i =  0;  i < c.size() ; i ++ )
        {
            for(int j = i+1 ; j < c.size() ; j ++)
            {
                if(c[i]!=c[j])
                {
                    ans = max(ans , j-i);
                }
            }
        }
        return ans;
    }
};