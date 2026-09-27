class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        unordered_map<char,int> mp1, mp2;

        for(auto &c : s1)
            mp1[c]++;

        int i = 0, j = 0;

        while(j < m)
        {
            mp2[s2[j]]++;

            while((j-i+1) > n)
            {
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0) mp2.erase(s2[i]);
                i++;
            }

            if(mp1 == mp2)
                return true;

            j++;
        }

        return false;
    }
};