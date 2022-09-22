class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = 0 ; i < s.length() ; i ++)
        {   //cout<<i<<endl;
            string temp = "";
            int t = i ;
            while(t < s.length()  && s[t] != ' ')
            {   temp+= s[t];
                t++;
            }
            reverse(temp.begin() , temp.end());
            ans += temp;
            ans += " ";
            i = t ;
         
            cout<<temp<<endl;
        }
        return ans.substr(0,s.length() );
    }
};