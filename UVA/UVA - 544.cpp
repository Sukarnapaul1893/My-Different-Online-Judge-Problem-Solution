#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

map<string,string> p;

string Find(string x){
    if(p[x]==x)return x;
    return p[x]=Find(p[x]);
}
void Union(string a, string b){
    p[Find(b)] = Find(a);
}
map<string, vector<string> >adj;
map<string , int>vis;
string a,b;
map<pair<string , string> ,ll >weight;
void dfs(string s, ll cur){
    vis[s]++;
    if(s==b){
        cout<<cur<<" tons\n\n";
        return ;
    }
    for(auto it=adj[s].begin();it!=adj[s].end();it++){

        if(vis[(*it)]==0){
            dfs((*it),min(cur,weight[{s,(*it)}]));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    int tc=0;
    while(cin>>n>>m){

        if(n==0 && m==0)break;

        tc++;

        vector<pair<ll,pair<string,string> > >vec;
        for(int i=0;i<m;i++){
            string u,v;
            ll w;
            cin>>u>>v>>w;
            p[u]=u;
            p[v]=v;

            vec.pb({w,{u,v}});
            weight[{u,v}]=w;
            weight[{v,u}]=w;
        }

        cin>>a>>b;
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());


        for(int i=0;i<m;i++){
            string u = vec[i].second.first;
            string v = vec[i].second.second;
            if(Find(u)==Find(v))continue;
            Union(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cout<<"Scenario #"<<tc<<"\n";
        dfs(a,100000000);
        vis.clear();
        adj.clear();
        p.clear();
        weight.clear();

    }

}
