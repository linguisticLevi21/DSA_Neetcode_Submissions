class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        deque<int> dq;
        vector<int> ans;

        while(j < n)
        {
            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[j])
                dq.pop_back();

            dq.push_back(j);

            // Remove elements outside window
            if(dq.front() < i)
                dq.pop_front();

            // Window is of size k
            if(j - i + 1 == k)
            {
                ans.push_back(nums[dq.front()]);
                i++;
            }

            j++;
        }

        return ans;
    }
};