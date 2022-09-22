class Solution {
public:
    bool buddyStrings(string s, string g) {
        
        int x = 0 ;
        if(s.length()!=g.length())
            return false;
        if(s.length()<2)
            return false;
        vector<pair<char , char>> op;
        map<char , int> x1 , x2;
        for(char el : s)
        {
            x1[el]++;
        }
        for(char el :  g)
        {
            x2[el]++;
        }
        bool has_ex = false;
        for(auto el : x1)
        {
            if(el.second>1)
                has_ex = true;
        }
        for(int i = 0 ; i  < s.length() ; i++)
        {
            if(s[i] != g[i]){
               op.push_back({s[i],g[i]});
               x++;
            }
        }
        cout<<x;
        if(x>2){
        return false;
        }
        else if(x == 2){
            pair<char,char> o1,o2;
            o1 = op[0];
            o2 = op[1];
            
            if(o1.first == o2.second && o1.second == o2.first)
                return true;
            else
                return false;
            
        }
        else if(x==1){
        return false;
        }
        else
        {
        if(x1.size() == 1 )
            return true;
        else
        {
            if(has_ex)
                return true;
            else
                return false;
        }
        }
       
    }
};