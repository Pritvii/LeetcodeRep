class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        if(k  > arr.size())
            return 0;
        int  i = 0 ; 
        int j = k-1 ; 
        //sort(arr.begin() , arr.end());
        int sum = 0;
        int ans = 0 ;
        for(int k = i ; k <=j ; k++)
        {
            sum += arr[k];
        }
        if(sum/k >= t)
            ans++;
        for(int i = j+1 ; i <arr.size() ; i ++)
        {
            int curr_el = arr[i];
            int rem_el = arr[i-k];
            
           // cout<<curr_el << " "<<rem_el<<endl;
            
            sum += curr_el;
            sum -= rem_el;
            float avg = (float)sum/k;
            if(avg >= t)
            {
                ans++;
            }
        }
        return ans;
    }
};