#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,m;
void input();
vector<int>adj[100005];
int mark[100005];
vector<pair<int,int> >ans;
map<pair<int,int> , int>edges;
void dfs(int s , int par){
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];
        if(u==par)continue;
        dfs(u,s);
    }
    if(mark[par]==0 && mark[s]==0){
        mark[par]++;
        mark[s]++;
        ans.pb({par,s});
    }
}
void solve(){
    dfs(1,0);
    vector<pair<int,pair<int,int> > >vec;
    for(int i=0;i<ans.size();i++){
        int u = ans[i].first;
        int v = ans[i].second;
        if(edges[{u,v}]!=0){
            vec.pb({edges[{u,v}],{u,v}});
        }
        else if(edges[{v,u}]!=0){
            vec.pb({edges[{v,u}],{v,u}});
        }
    }
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<"\n";
    for(int i=0;i<vec.size();i++){
        int u = vec[i].second.first;
        int v = vec[i].second.second;

        cout<<u<<" "<<v<<"\n";
    }
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
    Clear();
}

void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[{u,v}]=i+1;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
