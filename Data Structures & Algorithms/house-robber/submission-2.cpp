#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //int t[101];
    int rob(vector<int>& nums) {
        vector<int> t(nums.size()+1);
        int n = nums.size();
        if(n==1) return nums[0];
        //if(n==2) return max(nums[0],nums[1]);
        t[0] = 0;
        t[1] = nums[0];
        //t[2] = max(nums[0], nums[1]);
        int take = 0;
        int skip = 0;
        int mx = -1;
        for (int i = 2; i <= n; i++) {
            take = nums[i-1] + t[i - 2];
            skip = t[i - 1];
            t[i] = max(take, skip);
        }
        return t[n];
    }
};
