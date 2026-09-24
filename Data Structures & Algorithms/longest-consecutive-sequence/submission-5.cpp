class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        int ans = 1;
        int cnt = 1;
        set<int> s(nums.begin(),nums.end());
        for(int i : s)
        {
            
            if(s.count(i-1))
            {
                    cnt++;
            }
            else cnt = 1; 
            ans = max(ans,cnt);
            //cnt = 1;
        }
        return max(ans,cnt);
    }
};
