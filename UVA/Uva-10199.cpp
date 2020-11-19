#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,m;
int timer;
bool vis[105];
int tin[105];
int low[105];

unordered_map<int,string>city;
void input();
vector<int>adj[105];
set<string>ans;


void IS_CUTPOINT(int v){
    ans.insert(city[v]);
}

void dfs(int v, int par = -1){
    vis[v] = true;

    tin[v] = low[v] = timer++;

    int children= 0;

    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];

        if(u==par)continue;

        if(vis[u]==true){
            low[v] = min(low[v],tin[u]);
        }
        else{
            dfs(u,v);
            low[v] = min(low[v],low[u]);

            if(low[u]>=tin[v] && par!=-1){
                IS_CUTPOINT(v);
            }
            children++;
        }
    }
    if(par==-1 && children>1){
        IS_CUTPOINT(v);
    }
}

void find_cutpoints(){
    timer = 0;
    memset(vis,false,sizeof vis);
    memset(tin,-1,sizeof tin);
    memset(low,-1,sizeof low);

    for(int i=1;i<=n;i++){
        if(vis[i]==false)dfs(i);
    }
}
int tc;
void solve(){
    find_cutpoints();
    cout<<"City map #"<<tc<<": "<<ans.size()<<" camera(s) found\n";
    for(auto it = ans.begin();it!=ans.end();it++){
        cout<<(*it)<<"\n";
    }

}

void Clear(){
    ans.clear();
    city.clear();
    for(int i=1;i<=n;i++)adj[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>>n){
        if(n==0)exit(0);
        if(tc>0)cout<<"\n";
        tc++;
        input();
        solve();
        Clear();
    }
}

void input(){
    unordered_map<string,int>mp;


    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]=i+1;
        city[i+1] = s;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string u,v;
        cin>>u>>v;
        adj[mp[u]].pb(mp[v]);
        adj[mp[v]].pb(mp[u]);
    }
}
