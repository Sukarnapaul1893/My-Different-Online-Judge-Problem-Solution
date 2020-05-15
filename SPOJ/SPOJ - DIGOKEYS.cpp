//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


vector<int>adj[100005];
set<int>adjr[100005];


int vis[100005];
int level[100005];
int n;
void bfs(int s,int lvl){
    vis[s]=false;

    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int sz = q.size();
        lvl++;
        while(sz--){
            int u = q.front();
            q.pop();
            level[u]=lvl;
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                if(vis[v]==false){
                    q.push(v);
                    vis[v]=true;

                }
            }
        }

    }

}
vector<int >ans;
void dfs2(int s){

    if(s==n)return ;
    ans.pb(s);
    int parlevel = level[s];

    for(auto it = adjr[s].begin();it!=adjr[s].end();it++){
        int u = (*it);
        if(level[u]==parlevel-1){
            dfs2(u);
            break;
        }
    }
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    memset(vis,false,sizeof vis);
    int t;
    cin>>t;
    while(t--){

        cin>>n;
        for(int i=1;i<=n;i++)level[i]= n+2;
        for(int i=1;i<=n-1;i++){
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                int u ;
                cin>>u;
                adjr[i].insert(u);
                adj[u].pb(i);
            }
        }

        bfs(n,0);

        if(level[1]!=n+2){
            dfs2(1);
            cout<<ans.size()<<"\n";
            for(int i=0;i<ans.size();i++){

                cout<<ans[i];
                if(i!=ans.size()-1)cout<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"-1\n";
        }
        for(int i=0;i<=n;i++){
            vis[i]=false;
            adjr[i].clear();
            adj[i].clear();
        }
        ans.clear();
        if(t!=0)cout<<"\n";
    }
}
