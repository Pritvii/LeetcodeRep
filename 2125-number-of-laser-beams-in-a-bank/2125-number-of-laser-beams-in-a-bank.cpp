class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans =  0 ;
        map<int , int> x;
        //int n = 0 ;
        for(int i =0 ; i < bank.size() ; i ++){
            int temp = 0 ;
            for(char el : bank[i]){
                if(el == '1')
                    temp ++;
            }
            x[i] = temp;
        }
        int n = (int)bank.size();
        int arr[n];
        memset(arr , 0 ,  sizeof(arr));
        for( int i =0 ; i < n ; i ++){
            arr[i] = x[i];
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        vector<int> tempo;
        
        for(int i = 0 ; i < n ; i ++){
            if(arr[i]!=0){
                tempo.push_back(arr[i]);
            }
        }
        if(tempo.size() == 0 || tempo.size() == 1){
            return 0;
        }
        for(int i = 0 ;i < tempo.size() - 1 ; i ++){
            ans += tempo[i]*tempo[i+1];
        }
        return ans;
    }
};