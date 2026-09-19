#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int t[101];
int solve(int i, vector<int>& nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    if(i>=n) return 0;
    if(t[i]!=-1) return t[i];
    int take = 0;
    int skip = 0;
    take = nums[i] + solve(i+2,nums);
    skip = solve(i+1,nums);
    int mx = -1;
    mx = max(take,skip);
    return t[i] = mx;
}
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};
