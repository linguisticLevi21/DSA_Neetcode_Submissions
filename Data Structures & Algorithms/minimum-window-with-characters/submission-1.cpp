class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> mp1,mp2;
        int i = 0;
        int j = 0;
        pair<int,int> res = {-1,-1};
        int have = 0;
        int len = INT_MAX;
        for(auto &i : t) mp1[i]++;
        int need = mp1.size();

        while(j<n)
        {
            char c = s[j];
            //char k = s[i];
            mp2[c]++;
            if(mp1.count(c) && mp2[c]==mp1[c]) have++;
            while(have==need)
            {
                if(j-i+1 < len)
                {
                    len = j-i+1;
                    res = {i,j};
                }
            
            mp2[s[i]]--;
            if(mp1.count(s[i]) && mp2[s[i]]<mp1[s[i]]) have--;
             i++;
            }
            j++;
        }
        if(len == INT_MAX) return "";
        return s.substr(res.first, len);
    }
};
