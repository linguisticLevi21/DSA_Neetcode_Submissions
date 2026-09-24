class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<=1) return n;
        int cnt = 1;
        int ans = 1;
        for(int i = 1 ; i < nums.size();i++)
        {
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1)
            {
                cnt++;
            }
            else{
            ans = max(cnt,ans);
            cnt = 1;
            }
        }
        return max(ans,cnt);
    }
};
