class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        int ans = 1;
        int cnt = 1;
        set<int> s(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++)
        {
            
            if(!s.count(nums[i]-1))
            {
                cnt = 1;
                int val = nums[i];
                while(s.count(val+1))
                {
                    cnt++;
                    val += 1;
                }
            }
            //if(s.count(nums[i])) continue;
            //s.insert(nums[i]);
            ans = max(ans,cnt);
            //cnt = 1;
        }
        return max(ans,cnt);
    }
};
