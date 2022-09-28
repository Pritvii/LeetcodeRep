class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//return "";
        int minn = INT_MAX;
        string mins;
        for(string el : strs)
        {   
            int len = 0;
            
            for(char elo : el )
                len++;
            cout<<len<<endl;
            cout<<minn<<endl;
            if(len < minn )
            {   
                mins = el;
                minn = len;
            }
            
            //cout<<minn<<endl;
        }
        int ans = 0 ;
        string anss="";
        cout<<mins<<endl;
        for(int i = 0 ; i < minn ; i ++)
        {   int flag = 1;
            char curr = mins[i];
            for(string el : strs)
            {
                if(el[i]!=curr)
                {
                    flag = 0;
                    break;
                }
            }
         if(flag == 0)
         {
             return anss;
         }
            anss+=curr;
        }
        return anss;
                                                      
                                                      }
};