class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int>> ans(nums2.size() , {-1,-1});
        stack<pair<int , int>> st;
        st.push({nums2[0],0});
        int i = 1;
        while(!st.empty() && i < nums2.size())
        {
            int top = st.top().first;
            cout<<top<<endl;
            if(nums2[i] <= top)
                st.push({nums2[i],i});
            else
            {
                while(!st.empty() && st.top().first < nums2[i])
                {
                    ans[st.top().second] = {nums2[i],i};
                    st.pop();
                }
                st.push({nums2[i],i});
            }
            i++;
        }
        vector<int> anss;
        for(int el : nums1)
        {
            for(int i = 0 ; i < nums2.size() ; i ++)
            {
                if(nums2[i] == el)
                {
                    anss.push_back(ans[i].first);
                }
            }
        }
        return anss;
    }
};