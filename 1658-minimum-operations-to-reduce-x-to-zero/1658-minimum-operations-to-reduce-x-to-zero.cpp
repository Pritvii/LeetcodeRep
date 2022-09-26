// class Solution {
// public:
//     int solve(vector<int> &nums , int x  , int i ,  int j)
//     {
//         if(x == 0)
//             return 0;
//         if(x < 0 )
//             return INT_MAX-1;
        
//         int ans = INT_MAX - 1;
//         if(i+1 <= j)
//         ans = min(ans , 1 + solve(nums , x - nums[i] , i+1  , j));
//         if(i <= j-1)
//         ans = min(ans , 1  + solve(nums  , x - nums[j] , i , j - 1));
                  
//         return ans;
        
//     }
//     int minOperations(vector<int>& nums, int x) {
//         int xk = solve(nums , x , 0 , nums.size()-1);
//         if(xk > 214748364)
//             return -1;
//         else
//             return xk;
//     }
// };
class Solution {
public:
    /*
        the result must be like:
            
            ooooo----------oooooo
            left.           right.
            
        how to find the min length of (left + right)
        
        sol1:
            1. get the presum of left
            2. try to find complement portion (hash O(1) or two pointers O(1) or scan O(n)) for right portion (with length extending from 1 to n)
        
        sol2: since all the numbers are positive, presum will be in ascending order (we can binary search the complement portion with binary search O(logN))
        
    */
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        
        int lsum = 0, l = 0;
        while (l < n && lsum < x) {
            lsum += nums[l++];
        }
        if (lsum < x) return -1;
               
        // lsum == x or lsum > x
        int res = n + 1;
        if (lsum == x) res = l;
        
        int rsum = 0, r = n - 1;
        // note left is [0, l) or [0, i) in loop
        for (int i = l - 1; i >= 0; i--) {
            lsum -= nums[i];
            while (r >= 0 && rsum + lsum < x) {
                rsum += nums[r--];
            }
            // right is (r, n - 1]
            if (rsum + lsum == x) {
                res = min(res, i + n - 1 - r);
            }
        }
        
        return res > n ? -1 : res;
    }
};