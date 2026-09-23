class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> suff(n,0);
        vector<int> pref(n,0);

        pref[0] = nums[0];
        for(int i = 1 ;i < n ; i++)
        {
            pref[i] = pref[i-1] * nums[i];
        }

        suff[n-1] = nums[n-1];
        for(int i = n-2 ; i>= 0 ; i--)
        {
            suff[i] = suff[i+1] * nums[i];
        }

        for(int i = 0 ; i < n ; i++)
        {
            int left_val = (i == 0) ? 1 : pref[i-1];
            int right_val = (i == n-1) ? 1 : suff[i+1];
            ans[i] = left_val * right_val;
        }
        return ans;
    }
};
