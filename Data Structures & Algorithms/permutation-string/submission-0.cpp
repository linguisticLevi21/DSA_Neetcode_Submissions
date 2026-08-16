class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(char i:s1)
        {
            mp1[i]++;
        }
        int k = s1.size();
        int i = 0;
        int n = s2.size();
        int j = 0;

        while(j<n)
        {
            mp2[s2[j]]++;
            if(j - i + 1 == k)
            {
                if(mp1==mp2) return true;
                mp2[s2[i]]--;
                if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};