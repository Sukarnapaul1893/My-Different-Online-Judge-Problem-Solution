#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n;
int total;
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
    for(int i=0;i<n;i++){
        st.insert(Find(i));
    }
    if(st.size()>1)cout<<-1<<"\n";
    else cout<<total-ans<<"\n";
}

void Clear(){
    edges.clear();
    total=0;
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
    for(int i=0;i<n;i++)p[i]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int w;
            cin>>w;
            total+=w;
            if(w==0)continue;
            edges.pb({w,{i,j}});
        }
    }
}
