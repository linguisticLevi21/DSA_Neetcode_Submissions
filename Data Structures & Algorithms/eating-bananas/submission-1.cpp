class Solution {
public:
bool solve(vector<int>& piles, int mid, int h)
{
    int sum = 0;
    int n = piles.size();
    for(int i = 0 ; i < n ; i++)
    {
        sum += piles[i]/mid;
        if(piles[i]%mid!=0) sum +=1;
    }
    cout<<sum<<" ";
    return sum <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int i = 1;
        int j = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(solve(piles,mid,h))
            {
                ans = mid;
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};
