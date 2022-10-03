class Solution {
public:
    int minCost(string colors, vector<int>& time) 
    {
        int n = colors.size();
        int ans = 0;
        int i=0, j=i+1;
        
        for(; j<colors.size(); )
        {
            if(colors[i] == colors[j])
            {
                if(time[i] < time[j])
                {
                    ans += time[i];
                    i = j;
                }
                else
                    ans += time[j];
            }
            else
                i = j;
            
            j++;
        }
        return ans;
    }
};