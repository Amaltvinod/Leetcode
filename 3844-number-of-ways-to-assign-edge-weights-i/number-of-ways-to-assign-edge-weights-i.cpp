class Solution {
    int dfs(map<int,vector<int>>&map,int node,vector<int>&vis){
        if(vis[node])return 0;
        vis[node]=1;
        int ans=0;
        for(int neigh:map[node]){
            if(!vis[neigh])ans=max(ans,1+dfs(map,neigh,vis));
        }
        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        map<int,vector<int>>map;
        int mx=INT_MIN;
        for(vector<int>edge:edges){
            int u=edge[0];
            int v=edge[1];
            mx=max(u,mx);
            mx=max(v,mx);
            map[u].push_back(v);
            map[v].push_back(u);
        }
        vector<int>vis(mx+1,0);
        int height=dfs(map,1,vis);
        cout<<height<<endl;
        int odd=1;
        int even=1;
        const int mod=1e9+7;

        for(int i=2;i<=height;i++){
            int tmp=odd;
            odd=even+odd;
            odd%=mod;
            even=tmp+even;
            even%=mod;

        }
        
        return odd;


    }
};