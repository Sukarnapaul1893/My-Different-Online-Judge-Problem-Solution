#include<bits/stdc++.h>
#define pb push_back
using namespace std;


vector<int>adj[1000006];

int vis[1000006];

int ans;
int cur;
void dfs(int s, int d, int par){
    if(ans==-1)return;
    if(vis[s]>0 && vis[s]!=cur){
        ans=-1;
        return;
    }
    vis[s]=cur;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(d>0 && u!=par){
            dfs(u,d-1,s);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,r,m;
        cin>>n>>r>>m;
        for(int i=0;i<=n;i++){
            vis[i]=-1;
            adj[i].clear();
        }
        while(r--){
            int u,v;
            cin>>u>>v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        while(m--){
            int x ,y;
            cin>>x>>y;
            cur=x;
            if(ans!=-1){
                dfs(x,y,-1);
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==-1)ans=-1;
        }
        if(ans==-1){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
        ans=0;
        for(int i=0;i<=n;i++){
            vis[i]=-1;
            adj[i].clear();
        }
    }
}
