class Solution {
public:
    string pushDominoes(string t) {
    string s = t;    
    map<pair<pair<char , char> , int> ,pair<int, int>  > m;
    int i = 0 ; int j = s.length() - 1;
    if(s[i] == '.')
    {
        while( i<= s.length() - 1  && s[i]=='.' )
            i++;
    }
    if(s[j] == '.')
    {
        while(j >=0 &&  s[j]=='.' )
            j--;
    }
    
    if(i == s.length())
    {
        return s;
    }
    else
    {
        if(s[i] == 'L')
        {
            for(int k = 0 ; k < i  ; k ++)
                s[k] = 'L';
        }
        if(s[j] == 'R')
        {
            for(int k = j+1 ; k < s.length()  ; k++)
            {
                s[k] = 'R';
            }
        }
    }
   
    
    
    for(int k = i ; k < j ; k ++)
    {   int start_pos = k;
        
        if(s[k] == '.')
        {
            
            while(s[k] == '.')
                {
                    k++;
                }
            k--;
            m[{{s[start_pos-1] , s[k+1]},start_pos}] = {start_pos , k};
        }
        
    }
    
    for(auto el : m )
    {
        pair<pair<char , char > , int> chars;
        pair<int , int> pos;
        chars  = el.first;
        pos  = el.second;
        
        if(chars.first.first == 'L'&& chars.first.second == 'R')
        {
            continue;
        }
        else if(chars.first.first == 'R'&& chars.first.second == 'L')
        {
            int nd  = pos.first - pos.second + 1;
            if(nd%2 == 1)
            {   int st = pos.first ; 
                int end = pos.second;
                while(st <= end-2)
                {
                    s[st]   =   'R' ;
                    s[end]  =   'L' ;
                    st++;
                    end--;
                }
            }
            else
            {
                int st = pos.first ; 
                int end = pos.second;
                while(st <= end-1)
                {
                    s[st]   =   'R' ;
                    s[end]  =   'L' ;
                    st++;
                    end--;
                }
            }
        }
        else if(chars.first.first == 'R'&& chars.first.second == 'R')
        {
            int start = pos.first;
            int end  = pos.second;
            for(int p = start ; p <= end ; p++)
            {
                s[p] = 'R';
            }
        }
        else
        {   
            int start = pos.first;
            int end  = pos.second;
            for(int p = start ; p <= end ; p++)
            {
                s[p] = 'L';
            }   
            
        }
    }
    
    
    return s;
   }
};