class Solution {
public:
//typedef pair<int,pair<int,int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;

        for(auto &i : points)
        {
            auto a = i[0];
            auto b = i[1];

            auto x = pow((a*a + b*b),2);

            pq.push({x,{a,b}});
            while(pq.size()>k)
            {
                pq.pop();
            }
        }

        while(!pq.empty())
        {
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            ans.push_back({a,b});
            pq.pop();
        }
        return ans;
    }
};
