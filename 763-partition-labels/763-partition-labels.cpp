class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char , int > last;
        for(int i = 0 ; i < s.length() ; i ++)
        {
            last[s[i]] = i;
        }
        
        //cout<<last['a']<<endl;
        
        vector<int> partition;
        int last_parted = 0;
        for(int i = 0 ; i < s.length() ; i ++)
        {   
            //cout<<i<<endl;
            int last_i = last[s[i]];
            int flag = 0 ;
            int temp = i ;
            cout<<"i is "<<i<<"last_i is "<<last_i<<endl;
            for(int j = i + 1 ; j < last_i ; j ++)
            {
                if(last[s[j]] > last_i)
                {   flag = 1;
                    temp = j;
                    break;
                }
            }
            cout<<temp<<endl;
            if(flag == 0)
            {   //cout<<s[i]<<endl;
                cout<<last_parted<<" "<<last_i<<" "<<i<<" "<<endl;
                partition.push_back(last_i - last_parted +1);
                last_parted = last[s[i]] + 1;
                i = last_i ;
            }
            if(flag == 1)
             i =temp-1;
            //continue;
            //cout<<last_parted<<" "<<i<<" "<<endl;
            
        }
       
        return partition;
    }
};