class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,0);
        int zeros = 0;
        long long prod = 1;
        for(int i : nums)
        {
            if(i==0) zeros++;
            else prod *= i;
        }
        if(zeros>1)
        {
            return ans;
        }
        if(zeros == 0)
        {
            for(int i = 0 ; i < n ; i++)
            {
                ans[i] = prod / nums[i];
            }
        }
        else
        {
            int pos = -1;
            for(int i = 0; i < n ; i++)
            {
                if(nums[i] == 0)
                {
                    pos = i;
                    break;
                }
            }

            for(int i = 0; i < n ; i++)
            {
                if(i==pos)
                {
                    ans[i] = prod;
                }
                else{
                    ans[i] = 0;
                }
            }
        }
        return ans;
    }
};
