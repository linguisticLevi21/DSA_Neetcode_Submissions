#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int t[101];
int solve(vector<int> &nums,int i,int n)
{
    //int n = nums.size();
    if(i>n) return 0;
    if(t[i]!=-1) return t[i];
    int take = 0;
    int skip = 0;
    int mx = -1;
    take = nums[i]  + solve(nums, i+2,n);
    skip = solve(nums, i+1,n);
    mx = max(take,skip);
    return t[i] = mx;

}
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];
        memset(t,-1,sizeof(t));
        int a = solve(nums,0,n-2);
        memset(t,-1,sizeof(t));
        int b = solve(nums,1,n-1);
        return max(a,b);
        //return solve(nums,0,n);
    }
};

