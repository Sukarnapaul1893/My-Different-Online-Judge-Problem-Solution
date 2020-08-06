#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,q;
vector<int>adj[20004];
vector<pair<int,int> >queries;
void input();
const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;
int root1 , root2;
int par[2][MAXN][LG];


bool vis[2][50005];
int level[2][50005];

int lca(int u, int v, int idx){
	if(level[idx][u] < level[idx][v])	swap(u, v);
	int log = log2(level[idx][u]);
	for(int i = log; i >= 0; i--)
		if(level[idx][u]-level[idx][v] >= (1 << i))
			u = par[idx][u][i];
	if(u == v)
		return u;
	for(int i = log; i >= 0; i--){
		if(par[idx][u][i] != -1 && par[idx][u][i] != par[idx][v][i]){
			u = par[idx][u][i];
			v = par[idx][v][i];
		}
	}
	return par[idx][u][0];
}
void dfs(int u, int parent,int idx){
	level[idx][u] = level[idx][parent] + 1;
	par[idx][u][0] = parent;
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u,idx);
	}
}
void CallMeToFindLCA(){
    memset(par, -1, sizeof par);
    level[0][root1] = -1;
    level[1][root2] = -1;
    dfs(root1, -1,0);
    dfs(root2, -1,1);
    for(int idx=0;idx<2;idx++){
        for(int j = 1; j < LG; j++){
            for(int i = 1; i <= n; i++){
                if(par[idx][i][j-1] != -1)
                    par[idx][i][j] = par[idx][par[idx][i][j-1]][j-1];
            }
        }
    }
}
int dist[2][20004];
bool Vis[2][20004];

void Dfs(int s, int d, int idx){
    Vis[idx][s]=true;
    dist[idx][s]=d;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];

        if(Vis[idx][u]==false){
            Dfs(u,d+1,idx);
        }
    }
}

void Diameter(){
    Dfs(1,0,0);
    int mxu;
    int mxdist = 0;

    for(int i=1;i<=n;i++){
        if(mxdist<=dist[0][i]){
            mxdist = dist[0][i];
            mxu = i;
        }
    }
    Dfs(mxu,0,1);
    int mxv;
    mxdist = 0;

    for(int i=1;i<=n;i++){
        if(mxdist<=dist[1][i]){
            mxdist = dist[1][i];
            mxv = i;
        }
    }

    root1 = mxu;
    root2 = mxv;
}
int D1[20004];
int D2[20004];

void DistanceFromRoot1(int s,int d, int par){
    D1[s]=d;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(u==par)continue;
        DistanceFromRoot1(u,d+1,s);
    }
}

void DistanceFromRoot2(int s,int d, int par){
    D2[s]=d;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(u==par)continue;
        DistanceFromRoot2(u,d+1,s);
    }
}

int Call(int u,int d, int idx){
    if(d==0)return u;
    int ans;
    int p = 1;
    for(int i=0;;i++){
        if(p*2>d){
            ans = Call(par[idx][u][i],d-p,idx);
            break;
        }
        p*=2;
    }
    return ans;
}


void solve(){
    memset(vis,false,sizeof vis);
    Diameter();

    DistanceFromRoot1(root1,0,-1);
    DistanceFromRoot2(root2,0,-1);
    CallMeToFindLCA();

    for(int i=0;i<q;i++){
        int u = queries[i].first;
        int d = queries[i].second;

        if(D1[u]<d && D2[u]<d){
            cout<<0<<"\n";
        }
        else{
            if(D1[u]>=d){
                cout<<Call(u,d,0)<<"\n";
            }
            else{
                cout<<Call(u,d,1)<<"\n";
            }
        }
    }
}

void Clear(){
    for(int i=0;i<=n;i++){
        adj[i].clear();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
    Clear();
}

void input(){
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u , v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0;i<q;i++){
        int u ,d;
        cin>>u>>d;
        queries.pb({u,d});
    }
}
