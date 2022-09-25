class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        map<int , int > m;
        for(int el : spaces)
        {
            m[el]++;
        }
        string ans = "";
        
        for(int i = 0 ; i < s.length() ; i ++)
        {   
            if(m[i] == 1)
            {
                m[i] = 0;
                i--;
                ans+=" ";
                continue;
            }
            
            ans+=s[i];
        }
        return ans;
    }
};