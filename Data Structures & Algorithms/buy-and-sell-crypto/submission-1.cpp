class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit =  0;

        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 0; i < n ; i++)
        {
            mn = min(mn , prices[i]);
            for(int j = i+1 ; j < n ; j++)
            {
                mx = max(mx,prices[j]);
                profit = max(profit , prices[j]-prices[i]);
            }
        }
        return profit;
    }
};