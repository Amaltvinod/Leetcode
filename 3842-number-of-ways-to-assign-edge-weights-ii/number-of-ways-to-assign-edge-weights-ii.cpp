class Solution {
public:
    vector<vector<int>>U,adj;
    vector<int>depth,pow2;
    const int LOG=20;
    const int mod=1e9+7;
    int lca(int u,int v){
        if(depth[u]<depth[v])swap(u,v);
        int diff=depth[u]-depth[v];
        
        for(int i=LOG-1;i>=0;i--){
            if((diff>>i)&1){
                u=U[u][i];
            }
        }

        if(u==v)return u;
        for(int i=LOG-1;i>=0;i--){
            if(U[u][i]!=U[v][i]){
                u=U[u][i];
                v=U[v][i];
            }
        }
        return U[u][0];
    }

    void dfs(int u,int p){
        U[u][0]=p;

        for(int i=1;i<LOG;i++){
            U[u][i]=U[U[u][i-1]][i-1];
        }

        for(int v: adj[u]){
            if(v==p)continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }

    
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        U.assign(n+1,vector<int>(LOG));
        adj.assign(n+1,{});
        depth.assign(n+1,0);
        pow2.assign(n+1,1);
        for(vector<int>edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=n;i++){
            pow2[i]=pow2[i-1]*2 % mod;
        }

        dfs(1,1);
        vector<int>ans;
        for(vector<int>query:queries){
            int u=query[0];
            int v=query[1];
            int p=lca(u,v);
            int len=depth[u]+depth[v]-2*depth[p];
            
            if(len==0){
               ans.push_back(0);
            }else{
                ans.push_back(pow2[len-1]);
            }
        }
        return ans;




        
        
    }
};