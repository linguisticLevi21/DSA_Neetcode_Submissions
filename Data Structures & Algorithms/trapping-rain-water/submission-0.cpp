class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int lmax = height[l];
        int r = n-1;
        int rmax = height[r];
        int ans = 0;
        while(l<r)
        {
            if(rmax>lmax)
            {
                l++;
                lmax = max(height[l],lmax);
                ans += lmax-height[l];
            }
            else
            {
                r--;
                rmax = max(rmax,height[r]);
                ans += rmax-height[r];
            }
            
        }
        return ans;
    }
};
