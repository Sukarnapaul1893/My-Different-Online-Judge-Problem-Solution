#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n;

//Disjoint Set Union
int p[105]; //initially p[i] = i;
int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b)
{
    p[Find(b)] = Find(a); // Making the parent of a and b same
}

vector<pair<ll,pair<int,int> > >edges;


void input();

void solve(){
    sort(edges.begin(),edges.end());
    ll MIN = 0;
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        ll w = edges[i].first;

        if(Find(u)!=Find(v)){
            MIN +=w;
            Union(u,v);
        }
    }

    ll MAX = 0;
    for(int i=0;i<=n;i++)p[i]=i;
    for(int i=edges.size()-1;i>=0;i--){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        ll w = edges[i].first;

        if(Find(u)!=Find(v)){
            MAX +=w;
            Union(u,v);
        }
    }
    ll ans = MAX+MIN;
    if(ans%2==0)cout<<ans/2<<"\n";
    else cout<<ans<<"/2"<<"\n";
}

void Clear(){
    edges.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        cout<<"Case "<<i+1<<": ";
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n;

    while(true){
        int u , v, w;
        cin>>u>>v>>w;
        if(u==0 && v==0 && w==0)break;
        edges.pb({w,{u,v}});
    }
}
