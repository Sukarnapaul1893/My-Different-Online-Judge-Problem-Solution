#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int p[100005];

int Find(int x){
    if(p[x]==x)return x;
    return p[x]=Find(p[x]);
}
void Union(int a, int b){
    p[Find(b)] = Find(a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<pair<ll,pair<int,int> > >vec;
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;

        vec.pb({w,{u,v}});

    }

    sort(vec.begin(),vec.end());

    for(int i=1;i<=n;i++)p[i]=i;

    ll ans =0;
    for(int i=0;i<m;i++){
        int u = vec[i].second.first;
        int v = vec[i].second.second;
        if(Find(u)==Find(v))continue;
        Union(u,v);
        ans+=vec[i].first;
    }
    cout<<ans<<"\n";
}
