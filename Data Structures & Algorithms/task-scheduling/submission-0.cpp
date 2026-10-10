class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;

        for (auto& i : tasks)
            mp[i]++;

        for (auto& i : mp) {
            pq.push(i.second);
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;

            int cycle = n + 1;

            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq = freq - 1;
                if (freq > 0)
                    temp.push_back(freq);
                cycle--;
                time++;
            }

            for (int i : temp) {
                pq.push(i);
            }
            if (!pq.empty()) {
                time += cycle;
            }
        }
        return time;
    }
};