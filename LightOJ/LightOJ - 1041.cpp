#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,marker;
int total;
unordered_map<string , int>mark;
vector<pair<int,pair<int,int> > >edges;

//Disjoint Set Union
int p[100]; //initially p[i] = i;
int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b)
{
    p[Find(b)] = Find(a); // Making the parent of a and b same
}


void input();

void solve(){
    sort(edges.begin(), edges.end());

    ll ans = 0;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if(Find(u)!=Find(v)){
            Union(u,v);
            ans+=w;
        }
    }
    unordered_set<int>st;
    for(int i=1;i<marker;i++){
        st.insert(Find(i));
    }
    if(st.size()>1)cout<<"Impossible"<<"\n";
    else cout<<ans<<"\n";
}

void Clear(){
    edges.clear();
    mark.clear();
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
    for(int i=0;i<=50;i++)p[i]=i;
    marker = 1;
    for(int i=0;i<n;i++){
        int u,v,w;
        string a,b;
        cin>>a>>b>>w;
        if(mark[a]==0)mark[a]=marker++;
        if(mark[b]==0)mark[b]=marker++;
        u = mark[a];
        v = mark[b];

        edges.pb({w,{u,v}});
    }
}
