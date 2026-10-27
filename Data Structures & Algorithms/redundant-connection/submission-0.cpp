class Solution {
    class Disjointset
    {
        vector<int> parent,rank;
        public:
        Disjointset(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1,0);

            for(int i = 0 ; i < n ; i++)
            {
                parent[i] = i;
            }
        }
        
        int find(int x)
        {
            if(x==parent[x]) return x;
            return parent[x] = find(parent[x]);
        }

        void unionbyrank(int a , int b)
        {
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return;

            if(rank[pa]>rank[pb])
            {
                parent[pb] = pa;
            }
            else if(rank[pa]<rank[pb])
            {
                parent[pa] = pb;
            }
            else
            {
                parent[pa] = pb;
                rank[pb]++;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjointset ds(n);
        //vector<pair<int,int>> ans;
        for(int i = 0 ; i < n ; i++)
        {
            
                int a = edges[i][0];
                int b = edges[i][1];

                int pa = ds.find(a);
                int pb = ds.find(b);

                if(pa==pb) return {a,b}; 
                else ds.unionbyrank(a,b);
            
        }
        return {-1,-1};
    }
};
