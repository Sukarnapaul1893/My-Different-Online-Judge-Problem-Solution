#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n;
map<pair<int,int>,ll >weight;
const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;

int par[MAXN][LG];

vector<int>adj[50005];
vector<int>adj2[MAXN];
bool vis[50005];
int level[50005];

int lca(int u, int v){
	if(level[u] < level[v])	swap(u, v);
	int log = log2(level[u]);
	for(int i = log; i >= 0; i--)
		if(level[u]-level[v] >= (1 << i))
			u = par[u][i];
	if(u == v)
		return u;
	for(int i = log; i >= 0; i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
void dfs(int u, int parent){
	level[u] = level[parent] + 1;
	par[u][0] = parent;
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u);
	}
}
void CallMeToFindLCA(){
    memset(par, -1, sizeof par);
    level[0] = -1;
    dfs(0, -1);  //0-indexed
    for(int j = 1; j < LG; j++){
    	for(int i = 1; i <= n; i++){
    		if(par[i][j-1] != -1)
    			par[i][j] = par[par[i][j-1]][j-1];
    	}
    }
}

void input();
ll dist[50005];
void DfsDistance(int s, ll d){
    dist[s]=d;
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(vis[u]==true)continue;
        DfsDistance(u,d+weight[{u,s}]);
    }
}

void solve(){
    CallMeToFindLCA();
    memset(vis,false,sizeof vis);
    DfsDistance(0,0);
    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int LCA  = lca(a,b);
        ll ans = dist[a] + dist[b] - 2*dist[LCA];
        cout<<ans<<"\n";
    }

}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
}

void input(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        weight[{u,v}]=w;
        weight[{v,u}]=w;
    }
}
