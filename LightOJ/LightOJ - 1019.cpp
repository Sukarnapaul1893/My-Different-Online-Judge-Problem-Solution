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
#define PII pair<int,int>
#define mp make_pair
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


const int N=105;
int INF=1e7;

vector<PII> adj[N];     //node cost
int dis[N];
bool vis[N];

void Clear()
{
    fill (adj, adj + N, vector<PII> ());
    fill (dis, dis + N, INF);
    fill (vis, vis + N, false);
}
int n;
void dijkstra(int src){


	for (int i = 2; i <= n; ++i) {
		dis[i] =INF;
	}
    dis[1]=0;
	set<pair<int, int> > q;
	q.insert(make_pair(0, 1));
	while(!q.empty()){
		int u = (*q.begin()).second;
		q.erase(q.begin());
		for (int j = 0; j < adj[u].size(); ++j) {
			if (dis[u]+adj[u][j].second < dis[adj[u][j].first]){
				dis[adj[u][j].first] = dis[u]+adj[u][j].second;
				q.insert(make_pair(dis[adj[u][j].first], adj[u][j].first));
			}

		}
	}

}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++){
        Clear();
        int m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        dijkstra(1);

        if(dis[n]==INF){
            printf("Case %d: Impossible\n",tt+1);
        }
        else{
            printf("Case %d: %d\n",tt+1,dis[n]);
        }
    }
}
