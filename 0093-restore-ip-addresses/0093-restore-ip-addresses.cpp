class Solution {
public:
    set<string> ans;
    void solve(string s,int curr , int dot , string osf)
    {
        if(dot == 0 && curr == s.length()){
            if(osf[osf.length()-1] != '.')
            ans.insert(osf);
        return ;
        }
        if(dot == 0 && curr == s.length() - 1)
        {   cout<<osf<<endl;
            ans.insert(osf + s[curr] );
        }
        
        if(dot > 0 && curr >= s.length()-1)
            return ;
        
        if(dot == 0 )
        {   if(s[curr] == '0' && curr < s.length()-1)
                return ;
            if(s[curr] == '0' && curr == s.length() - 1)
                ans.insert(osf + "0");
            long long num = 0 ;
            int j = 0;
            for(int i = s.length()-1 ; i >= curr ; i--)
            {
                num += pow(10,j)*(s[i]-'0');
                j++;
            }
             if(num <= 255)
                 ans.insert(osf + to_string(num));
             return;
        }
        
        
        if(s[curr]  == '0'){
            solve(s , curr + 1 , dot-1,osf + "0." );
            return ;
        }
        else{
        string one = "";
        one += s[curr];
        solve(s,curr + 1 , dot-1 ,osf + s[curr] + ".");
        string two = "" , three = "";
        if(curr + 1 < s.length()){
            two = to_string(s[curr+1]-'0' + 10*(s[curr] - '0'));
        }
        if(curr + 2 < s.length()){
            three = "";
            three = to_string(s[curr+2]-'0' + (10*(s[curr+1]-'0')) + (100*(s[curr]-'0'))); 
        }
        if(curr + 2 <= s.length())
        solve(s , curr  + 2 , dot-1 , osf + two +  ".");
        if(curr + 3  <= s.length()){
            if(stoi(three)<= 255){
                cout<<stoi(three)<<endl;
            solve(s , curr + 3  , dot -1 , osf + three + "." );
            }
        }
        
    }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12)
            return {};
        solve(s , 0  , 3 , "");
        vector<string> anss;
        for(string el : ans)
            anss.push_back(el);
        return anss;
    }
};