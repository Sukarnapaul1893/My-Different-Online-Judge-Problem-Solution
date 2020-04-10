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


vector<int>adj[20005];
bool vis[20005];
int col[20005];
void Clear(){
    for(int i=0;i<=20005;i++)vis[i]=false;
    for(int i=0;i<=20005;i++)col[i]=0;
    for(int i=0;i<=20005;i++)adj[i].clear();
}

int t1,t2;
void dfs(int s){
    if(col[s]==0){
        col[s]=1;
        t1++;
    }
    int c = col[s];
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++){

        int u = adj[s][i];

        if(vis[u]==false){
            if(c==1)col[u]=2,t2++;
            if(c==2)col[u]=1,t1++;
            dfs(u);
        }
    }
}
int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        Clear();
        int n;
        scanf("%d",&n);

        int start;
        set<int>st;
        for(int i=0;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            st.insert(u);
            st.insert(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int ans =0;
        for(auto it=st.begin();it!=st.end();it++){
            int i = (*it);
            t1=0,t2=0;
            if(vis[i]==false)dfs(i);
            ans+=max(t1,t2);
        }

        printf("Case %d: %d\n",tt+1,ans);
    }
}
