class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.length() - 1;
        for(int i = s.length() - 1; i>=0 ; i --)
        {   j = i;
            if(s[i]!=' ')
                break;
        }
        string ans = "";
        for(int i = j ; i>=0 ; i--)
        {   
            if(s[i] == ' ')
                break;
            ans = ans + s[i];
            
        }
        return ans.length();
    }
};