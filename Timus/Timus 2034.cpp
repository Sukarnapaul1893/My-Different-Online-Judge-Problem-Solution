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

vector<int>adj[300005];
bool vis[300005];

//level[0][i] = shortest distance form r to i
//level[1][i] = shortest distance form start to i

int level[2][300005];




void bfs(int s, int x){
    vis[s]=true;
    queue<int >q;
    q.push(s);
    int lvl = 0;
    level[x][s]=lvl;
    while(!q.empty()){
        int sz = q.size();
        lvl++; //bfs level
        while(sz--){
            int u = q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                int cur = adj[u][i];
                if(vis[cur]==false){
                    vis[cur]=true;
                    q.push(cur);
                    level[x][cur]=lvl;

                }
            }
        }
    }
}


int mxans;
int start;

//adjacency List of the new directed graph
vector<int>Adj[300005];

bool revvis[300005];

//stores indegree for each node of the directed graph
int Indegree[300005];
void revdfs(int s){
    revvis[s]=true;
    if(s==start)return ;
    for(int i=0;i<adj[s].size();i++){
        int u = adj[s][i];

        if(revvis[u]==false && level[1][s]==level[1][u]+1){
            Adj[s].pb(u);
            Indegree[u]++;
            revvis[u]=true;
            revdfs(u);
        }
        else if(revvis[u]==true && level[1][s]==level[1][u]+1){
            Adj[s].pb(u);
            Indegree[u]++;
        }
    }
}

//ans[i] holds the answer for the ith node (dynamic programming)
int ans[300005];
void dfs(int s, int mnans){
    if(s==start){
        return;
    }
    for(int i=0;i<Adj[s].size();i++){
        int u = Adj[s][i];
        int ind = --Indegree[u];
        ans[u] = max(ans[u],mnans);
        //when we have done calculation for all incoming edges
        //of the current node , we will go further
        if(ind==0){
            ans[u]=min(ans[u],level[0][u]);
            dfs(u,ans[u]);
        }
    }
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)vis[i]=false;
    for(int i=0;i<m;i++){
        int u ,v;
        cin>>u>>v;
        //Make adjacency List
        adj[u].pb(v);
        adj[v].pb(u);

    }
    int t,r;
    cin>>start>>t>>r;

    //calculate shortest distance of all nodes from r
    bfs(r,0);
    for(int i=0;i<=n;i++)vis[i]=false;

    //calculate shortest distance of all nodes from start
    bfs(start,1);

    for(int i=0;i<=n;i++)vis[i]=false;
    for(int i=0;i<=n;i++)revvis[i]=false;

    //Make a directed graph with all possible shortest paths from t to start
    revdfs(t);

    ans[t]=level[0][t];

    //it calculates the ultimate answer
    dfs(t,ans[t]);
    cout<<ans[start]<<"\n";

}
