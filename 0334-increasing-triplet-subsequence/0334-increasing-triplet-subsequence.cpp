class Solution {
public:
//     bool increasingTriplet(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> dp(n+1 , INT_MAX);
//         dp[0]  = INT_MIN;
//         int ans = 1;
//         for(int i = 0 ; i < n ; i ++)
//         {  
//             int idx = (upper_bound(dp.begin(),dp.end(),nums[i]) - dp.begin());
//             if(idx == n+1)
//             {   if(ans + 1 < )
//                 dp[ans+1]
//             }
                
//             if(idx < n+1 && nums[i] < dp[idx] && nums[i] > dp[idx-1])
//             {
//                 dp[idx] = nums[i];
//                 ans = max(ans , idx);
//             }
//         }
//         for(int i = 0 ; i < n+1;i++)
//             cout<<dp[i]<<" ";
//         cout<<endl;
//         int cnt = 0 ;
//         int i = 1;
//         while(i < n + 1)
//         {
//             if(dp[i]!=INT_MAX)
//                 cnt++;
//             else
//                 break;
//             i++;
//         }
//         cout<<ans;
//             if(ans>=3)
//                 return true;
//             else
//                 return false;
//     }
     bool increasingTriplet(vector<int>& nums) {
    int first=INT_MAX,second=INT_MAX; //set max value
    
	//scracth value from vector
    for(auto &el:nums){
        if(el<=first){
            first=el; //set first as el
        }else if(el<=second){ //when element greater than first element
            second=el; //set second as el
        }else{ //here come when two element 3rd element is greater than first and second ..so it is true
            return true; //return the result
        }
    }
    
	//return as false
    return false;
}
};